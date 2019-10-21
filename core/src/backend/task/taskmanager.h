#pragma once
#include <common.h>
#include <backend/task/TaskBackend.h>
#include <backend/task/TaskData.h>

namespace spruce {
	namespace task {
		extern uint64 taskId;

		void init() noexcept;
		void free() noexcept;
		void addTask(uint64 id, TaskData* data, TaskBackend* taskBackend) noexcept;
		[[nodiscard]] TaskBackend* getNextTask(bool main) noexcept;
		bool executeMainTask() noexcept;
		bool executeGraphicsTask(bool concurrent) noexcept;
		void incrementRef(uint64 id) noexcept;
		void deincrementRef(uint64 id) noexcept;
	}
}
