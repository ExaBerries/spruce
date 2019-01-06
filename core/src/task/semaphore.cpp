#include <task/semaphore.h>

namespace spruce {
	semaphore::semaphore() {
		locked = false;
	}

	semaphore::~semaphore() {
	}

	void semaphore::lock() {
		locked = true;
	}

	void semaphore::unlock() {
		locked = false;
	}

	void semaphore::wait() {
		while (locked);
	}
}
