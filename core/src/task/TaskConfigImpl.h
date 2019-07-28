#pragma once

namespace spruce {
	namespace task {
		template <typename OUTPUT, typename ... TYPES>
		TaskConfig<OUTPUT(TYPES...)>::TaskConfig(std::function<OUTPUT(TYPES...)> function, task::TaskPriority priority, bool concurrent, TYPES ... args) : args(args...) {
			this->function = function;
			this->priority = priority;
			this->concurrent = concurrent;
		}
	}

	template <typename RETURN, typename ... TYPES>
	Task<RETURN(TYPES...)> createTask(TaskConfig<RETURN(TYPES...)> config) {
		uint64 id = task::taskId++;
		task::TaskData* taskData = new task::TaskData(sizeof(RETURN), [](void* data) {((RETURN*)data)->~RETURN();});
		new (taskData->data) RETURN();
		Task<RETURN(TYPES...)> task(id, taskData->complete, *((RETURN*)taskData->data));
		task.priority = config.priority;
		task::TaskBackend* taskBackend = new task::TaskBackend(id, taskData->complete);
		taskBackend->priority = config.priority;
		taskBackend->concurrent = config.concurrent;
		taskBackend->functionData = new task::FunctionDataTemplate<RETURN, TYPES...>((RETURN*)taskData->data, config.function, config.args, id);
		addTask(id, taskData, taskBackend);
		return task;
	}

	template <typename ... TYPES>
	Task<void(TYPES...)> createTask(TaskConfig<void(TYPES...)> config) {
		uint64 id = task::taskId++;
		task::TaskData* taskData = new task::TaskData(sizeof(bool), [](void* data) {(void)data;});
		Task<void(TYPES...)> task(id, taskData->complete);
		task.priority = config.priority;
		task::TaskBackend* taskBackend = new task::TaskBackend(id, taskData->complete);
		taskBackend->priority = config.priority;
		taskBackend->concurrent = config.concurrent;
		taskBackend->functionData = new task::FunctionDataTemplate<void, TYPES...>((bool*)taskData->data, config.function, config.args, id);
		addTask(id, taskData, taskBackend);
		return task;
	}
}
