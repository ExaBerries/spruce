#pragma once
#include <common.h>

namespace spruce {
	namespace task {
		class TaskData {
			public:
				uint64 size;
				void* data;
				bool complete;
				void(*dataDestructor)(void*);

				TaskData(size_t size, void(*dataDestructor)(void*));
				TaskData(const TaskData& taskData) = delete;
				TaskData(TaskData&&) noexcept = delete;
				~TaskData();

				TaskData& operator=(const TaskData&) = delete;
				TaskData& operator=(TaskData&&) noexcept = delete;
		};
	}
}
