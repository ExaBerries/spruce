#pragma once
#include <common.h>

namespace spruce {
	namespace task {
		class TaskData {
			public:
				size_t size;
				void* data;
				bool complete;
				void(*dataDestructor)(void*);

				TaskData(size_t size, void(*dataDestructor)(void*));
				TaskData(const TaskData& taskData) = delete;
				virtual ~TaskData();
		};
	}
}
