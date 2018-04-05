#pragma once
#include <backend/task/FunctionDataTemplate.h>
#include <common.h>
#include <task/Task.h>
#include <backend/task/TaskBackend.h>
#include <backend/task/TaskData.h>

namespace spruce {
	namespace task {
		void init();
		void free();
		void addTask(uint64 id, TaskData* data, TaskBackend* taskBackend);
		TaskBackend* getNextTask(bool main);
		extern uint64 taskId;
	}

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
		taskBackend->functionData = new task::FunctionDataTemplate<void, TYPES...>((void*)data->data, function, std::tuple<TYPES...>(args...));
		addTask(id, data, taskBackend);
		return task;
	}
}
