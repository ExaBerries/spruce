#include <backend/task/TaskBackend.h>

namespace spruce {
	namespace task {
		void incrementRef(uint64 id);
		void deincrementRef(uint64 id);

		TaskBackend::TaskBackend(uint64 id, bool& complete) : complete(complete) {
			this->id = id;
			this->functionData = nullptr;
			this->concurrent = false;
			this->priority = task::LOW;
			incrementRef(id);
		}

		TaskBackend::~TaskBackend() {
			functionData.free();
			deincrementRef(id);
		}
	}
}
