#pragma once
#include <common.h>

namespace spruce {
	namespace task {
		class TaskData {
			public:
				size_t size;
				void* data;
				bool complete;

				TaskData(size_t size);
				TaskData(const TaskData& taskData) = delete;
				virtual ~TaskData();
		};
	}
}
