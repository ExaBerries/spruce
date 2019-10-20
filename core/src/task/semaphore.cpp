#include <task/semaphore.h>

namespace spruce {
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
