#pragma once
#include <types.h>

namespace spruce {
	struct semaphore {
		bool locked;

		semaphore();
		virtual ~semaphore();

		void lock();
		void unlock();
		void wait();
	};
}
