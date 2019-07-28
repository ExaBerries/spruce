#pragma once

namespace spruce {
	namespace task {
		template <typename OUTPUT, typename ... TYPES>
		Task<OUTPUT(TYPES...)>::Task(uint64 id, bool& complete, OUTPUT& output) : complete(complete), output(output) {
			this->id = id;
			priority = task::LOW;
			task::incrementRef(id);
		}

		template <typename OUTPUT, typename ... TYPES>
		Task<OUTPUT(TYPES...)>::Task(const Task& task) : complete(task.complete), output(task.output) {
			this->id = task.id;
			this->priority = task.priority;
			task::incrementRef(id);
		}

		template <typename OUTPUT, typename ... TYPES>
		Task<OUTPUT(TYPES...)>::~Task() {
			task::deincrementRef(id);
		}

		template <typename OUTPUT, typename ... TYPES>
		Task<OUTPUT(TYPES...)>& Task<OUTPUT(TYPES...)>::operator=(const Task& task) {
			this->id = task.id;
			task::incrementRef(id);
			return *this;
		}

		template <typename ... TYPES>
		Task<void(TYPES...)>::Task(uint64 id, bool& complete) : complete(complete) {
			this->id = id;
			priority = task::LOW;
			task::incrementRef(id);
		}

		template <typename ... TYPES>
		Task<void(TYPES...)>::Task(const Task& task) : complete(task.complete) {
			this->id = task.id;
			this->priority = task.priority;
			task::incrementRef(id);
		}

		template <typename ... TYPES>
		Task<void(TYPES...)>::~Task() {
			task::deincrementRef(id);
		}

		template <typename ... TYPES>
		Task<void(TYPES...)>& Task<void(TYPES...)>::operator=(const Task& task) {
			this->id = task.id;
			task::incrementRef(id);
			return *this;
		}
	}

	template <typename RETURN, typename ... TYPES>
	Task<RETURN(TYPES...)> createTask(std::function<RETURN(TYPES...)> function, task::TaskPriority priority, bool concurrent, TYPES ... args) {
		uint64 id = task::taskId++;
		task::TaskData* taskData = new task::TaskData(sizeof(RETURN), [](void* data) {((RETURN*)data)->~RETURN();});
		new (taskData->data) RETURN();
		Task<RETURN(TYPES...)> task(id, taskData->complete, *((RETURN*)taskData->data));
		task.priority = priority;
		task::TaskBackend* taskBackend = new task::TaskBackend(id, taskData->complete);
		taskBackend->priority = priority;
		taskBackend->concurrent = concurrent;
		taskBackend->functionData = new task::FunctionDataTemplate<RETURN, TYPES...>((RETURN*)taskData->data, function, std::tuple<TYPES...>(args...), id);
		addTask(id, taskData, taskBackend);
		return task;
	}

	template <typename ... TYPES>
	Task<void(TYPES...)> createTask(std::function<void(TYPES...)> function, task::TaskPriority priority, bool concurrent, TYPES ... args) {
		uint64 id = task::taskId++;
		task::TaskData* taskData = new task::TaskData(sizeof(bool), [](void* data) {(void)data;});
		Task<void(TYPES...)> task(id, taskData->complete);
		task.priority = priority;
		task::TaskBackend* taskBackend = new task::TaskBackend(id, taskData->complete);
		taskBackend->priority = priority;
		taskBackend->concurrent = concurrent;
		taskBackend->functionData = new task::FunctionDataTemplate<void, TYPES...>((bool*)taskData->data, function, std::tuple<TYPES...>(args...), id);
		addTask(id, taskData, taskBackend);
		return task;
	}
}
