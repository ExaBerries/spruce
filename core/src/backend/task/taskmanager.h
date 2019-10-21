#pragma once
#include <common.h>
#include <backend/task/TaskBackend.h>
#include <backend/task/TaskData.h>

namespace spruce {
	namespace task {
		extern uint64 taskId;

		void init();
		void free();
		void addTask(uint64 id, TaskData* data, TaskBackend* taskBackend);
		[[nodiscard]] TaskBackend* getNextTask(bool main);
		bool executeMainTask();
		bool executeGraphicsTask(bool concurrent);
		void incrementRef(uint64 id);
		void deincrementRef(uint64 id);
	}
}
