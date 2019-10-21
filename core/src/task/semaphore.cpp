#include <task/semaphore.h>

namespace spruce {
	void semaphore::lock() noexcept {
		locked = true;
	}

	void semaphore::unlock() noexcept {
		locked = false;
	}

	void semaphore::wait() noexcept {
		while (locked) {};
	}
}
