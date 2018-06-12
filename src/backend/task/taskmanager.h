#pragma once
#include <common.h>
#include <backend/task/TaskBackend.h>
#include <backend/task/TaskData.h>
#include <graphics/CommandBuffer.h>

namespace spruce {
	namespace task {
		void init();
		void free();
		void addTask(uint64 id, TaskData* data, TaskBackend* taskBackend);
		TaskBackend* getNextTask(bool main);
		extern uint64 taskId;
		bool executeMainTask();
		bool executeGraphicsTask(bool concurrent);
		void incrementRef(uint64 id);
		void deincrementRef(uint64 id);
	}
}
