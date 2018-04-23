#pragma once
#include <common.h>
#include <task/TaskPriority.h>
#include <task/Task.h>
#include <backend/task/taskmanager.h>
#include <tuple>

namespace spruce {
	template <typename T>
	class TaskConfig;

	template <typename OUTPUT, typename ... TYPES>
	class TaskConfig<OUTPUT(TYPES...)> {
		public:
			std::function<OUTPUT(TYPES...)> function;
			task::TaskPriority priority;
			bool concurrent;
			std::tuple<TYPES...> args;

			TaskConfig(std::function<OUTPUT(TYPES...)> function, task::TaskPriority priority, bool concurrent, TYPES ... args) : args(args...) {
				this->function = function;
				this->priority = priority;
				this->concurrent = concurrent;
			}

			~TaskConfig() {
			}
	};

	template <typename RETURN, typename ... TYPES>
	Task<RETURN(TYPES...)> createTask(TaskConfig<RETURN(TYPES...)> config) {
		uint64 id = task::taskId++;
		task::TaskData* data = new task::TaskData(sizeof(RETURN));
		new (data->data) RETURN();
		Task<RETURN(TYPES...)> task(id, data->complete, *((RETURN*)data->data));
		task.priority = config.priority;
		task::TaskBackend* taskBackend = new task::TaskBackend(id, data->complete);
		taskBackend->priority = config.priority;
		taskBackend->concurrent = config.concurrent;
		taskBackend->functionData = new task::FunctionDataTemplate<RETURN, TYPES...>((RETURN*)data->data, config.function, config.args);
		addTask(id, data, taskBackend);
		return task;
	}

	template <typename ... TYPES>
	Task<void(TYPES...)> createTask(TaskConfig<void(TYPES...)> config) {
		uint64 id = task::taskId++;
		task::TaskData* data = new task::TaskData(sizeof(bool));
		Task<void(TYPES...)> task(id, data->complete);
		task.priority = config.priority;
		task::TaskBackend* taskBackend = new task::TaskBackend(id, data->complete);
		taskBackend->priority = config.priority;
		taskBackend->concurrent = config.concurrent;
		taskBackend->functionData = new task::FunctionDataTemplate<void, TYPES...>((bool*)data->data, config.function, config.args);
		addTask(id, data, taskBackend);
		return task;
	}
}
