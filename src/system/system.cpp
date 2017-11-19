#include <system/system.h>
#include <backend/os.h>
#include <thread>
#include <chrono>

namespace spruce {
	namespace sys {
		uint16 getCPUThreadCount() {
			return std::thread::hardware_concurrency();
		}

		float timeSec() {
			auto timePoint = std::chrono::high_resolution_clock::now();
			std::chrono::seconds time = std::chrono::duration_cast<std::chrono::seconds>(timePoint.time_since_epoch());
			return time.count();
		}

		uint64 timeNano() {
			auto timePoint = std::chrono::high_resolution_clock::now();
			std::chrono::nanoseconds time = std::chrono::duration_cast<std::chrono::nanoseconds>(timePoint.time_since_epoch());
			return time.count();
		}
	}
}
