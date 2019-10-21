#pragma once
#include <types.h>

namespace spruce {
	struct semaphore {
		bool locked = false;

		void lock() noexcept;
		void unlock() noexcept;
		void wait() noexcept;
	};
}
