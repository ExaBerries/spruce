#include <system/time.h>
#include <chrono>

namespace spruce {
	namespace sys {
		float timeSec() noexcept {
			auto timePoint = std::chrono::high_resolution_clock::now();
			std::chrono::seconds time = std::chrono::duration_cast<std::chrono::seconds>(timePoint.time_since_epoch());
			return time.count();
		}

		int64 timeNano() noexcept {
			auto timePoint = std::chrono::high_resolution_clock::now();
			std::chrono::nanoseconds time = std::chrono::duration_cast<std::chrono::nanoseconds>(timePoint.time_since_epoch());
			return time.count();
		}
	}
}
