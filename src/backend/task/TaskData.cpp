#include <backend/task/TaskData.h>

namespace spruce {
	namespace task {
		TaskData::TaskData(size_t size) {
			this->size = size;
			this->data = malloc(size);
			this->complete = false;
		}

		TaskData::~TaskData() {
			free(data);
		}
	}
}
