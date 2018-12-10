#include <backend/task/TaskData.h>

namespace spruce {
	namespace task {
		TaskData::TaskData(size_t size, void(*dataDestructor)(void*)) {
			this->size = size;
			this->data = malloc(size);
			this->complete = false;
			this->dataDestructor = dataDestructor;
		}

		TaskData::~TaskData() {
			dataDestructor(data);
			free(data);
		}
	}
}
