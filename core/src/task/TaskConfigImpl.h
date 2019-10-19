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
	[[nodiscard]] Task<RETURN(TYPES...)> createTask(TaskConfig<RETURN(TYPES...)> config) {
		static_assert(std::is_default_constructible_v<RETURN>);
		static_assert(std::is_destructible_v<RETURN>);
		uint64 id = task::taskId++;
		owner<task::TaskData> taskData = new task::TaskData(sizeof(RETURN), [](void* data) {static_cast<RETURN*>(data)->~RETURN();});
		new (taskData->data) RETURN();
		Task<RETURN(TYPES...)> task(id, taskData->complete, *static_cast<RETURN*>(taskData->data));
		task.priority = config.priority;
		owner<task::TaskBackend> taskBackend = new task::TaskBackend(id, taskData->complete);
		taskBackend->priority = config.priority;
		taskBackend->concurrent = config.concurrent;
		taskBackend->functionData = new task::FunctionDataTemplate<RETURN, TYPES...>(static_cast<RETURN*>(taskData->data), config.function, config.args, id);
		addTask(id, taskData, taskBackend);
		return task;
	}

	template <typename ... TYPES>
	[[nodiscard]] Task<void(TYPES...)> createTask(TaskConfig<void(TYPES...)> config) {
		uint64 id = task::taskId++;
		owner<task::TaskData> taskData = new task::TaskData(sizeof(bool), []([[maybe_unused]] void* data) {});
		Task<void(TYPES...)> task(id, taskData->complete);
		task.priority = config.priority;
		owner<task::TaskBackend> taskBackend = new task::TaskBackend(id, taskData->complete);
		taskBackend->priority = config.priority;
		taskBackend->concurrent = config.concurrent;
		taskBackend->functionData = new task::FunctionDataTemplate<void, TYPES...>(static_cast<bool*>(taskData->data), config.function, config.args, id);
		addTask(id, taskData, taskBackend);
		return task;
	}
}
