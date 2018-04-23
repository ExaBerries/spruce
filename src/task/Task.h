#pragma once
#include <common.h>
#include <task/TaskPriority.h>
#include <backend/task/TaskData.h>
#include <backend/task/FunctionDataTemplate.h>
#include <backend/task/taskmanager.h>
#include <tuple>

namespace spruce {
	template <typename T>
	class Task;

	template <typename OUTPUT, typename ... TYPES>
	class Task<OUTPUT(TYPES...)> {
		public:
			task::TaskPriority priority;
			bool& complete;
			OUTPUT& output;
			uint64 id;

			Task(uint64 id, bool& complete, OUTPUT& output) : complete(complete), output(output) {
				this->id = id;
				priority = task::LOW;
				task::incrementRef(id);
			}

			Task(const Task& task) : complete(task.complete), output(task.output) {
				this->id = task.id;
				this->priority = task.priority;
				task::incrementRef(id);
			}

			~Task() {
				task::deincrementRef(id);
			}
	};

	template < typename ... TYPES>
	class Task<void(TYPES...)> {
		public:
			task::TaskPriority priority;
			bool& complete;
			uint64 id;

			Task(uint64 id, bool& complete) : complete(complete) {
				this->id = id;
				priority = task::LOW;
				task::incrementRef(id);
			}

			Task(const Task& task) : complete(task.complete) {
				this->id = task.id;
				this->priority = task.priority;
				task::incrementRef(id);
			}

			~Task() {
				task::deincrementRef(id);
			}
	};

	template <typename RETURN, typename ... TYPES>
	Task<RETURN(TYPES...)> createTask(std::function<RETURN(TYPES...)> function, task::TaskPriority priority, bool concurrent, TYPES ... args) {
		uint64 id = task::taskId++;
		task::TaskData* data = new task::TaskData(sizeof(RETURN));
		new (data->data) RETURN();
		Task<RETURN(TYPES...)> task(id, data->complete, *((RETURN*)data->data));
		task.priority = priority;
		task::TaskBackend* taskBackend = new task::TaskBackend(id, data->complete);
		taskBackend->priority = priority;
		taskBackend->concurrent = concurrent;
		taskBackend->functionData = new task::FunctionDataTemplate<RETURN, TYPES...>((RETURN*)data->data, function, std::tuple<TYPES...>(args...));
		addTask(id, data, taskBackend);
		return task;
	}

	template <typename ... TYPES>
	Task<void(TYPES...)> createTask(std::function<void(TYPES...)> function, task::TaskPriority priority, bool concurrent, TYPES ... args) {
		uint64 id = task::taskId++;
		task::TaskData* data = new task::TaskData(sizeof(bool));
		Task<void(TYPES...)> task(id, data->complete);
		task.priority = priority;
		task::TaskBackend* taskBackend = new task::TaskBackend(id, data->complete);
		taskBackend->priority = priority;
		taskBackend->concurrent = concurrent;
		taskBackend->functionData = new task::FunctionDataTemplate<void, TYPES...>((bool*)data->data, function, std::tuple<TYPES...>(args...));
		addTask(id, data, taskBackend);
		return task;
	}
}
