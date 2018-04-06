#pragma once
#include <common.h>
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
}
