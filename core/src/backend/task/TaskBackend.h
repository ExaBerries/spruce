#pragma once
#include <common.h>
#include <backend/task/FunctionData.h>
#include <task/TaskPriority.h>

namespace spruce {
	namespace task {
		class TaskBackend {
			public:
				FunctionData* functionData;
				TaskPriority priority;
				bool concurrent;
				bool& complete;
				uint64 id;

				TaskBackend(uint64 id, bool& complete);
				TaskBackend(const TaskBackend& task) = delete;
				TaskBackend(TaskBackend&&) noexcept = delete;
				~TaskBackend();

				TaskBackend& operator=(const TaskBackend&) = delete;
				TaskBackend& operator=(TaskBackend&&) noexcept = delete;
		};
	}
}
