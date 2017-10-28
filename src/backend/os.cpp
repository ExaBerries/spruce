#include <backend/os.h>
#include <chrono>

namespace spruce {
	namespace os {
		float timeSec() {
			auto timePoint = std::chrono::high_resolution_clock::now();
			std::chrono::seconds time = std::chrono::duration_cast<std::chrono::seconds>(timePoint.time_since_epoch());
			return time.count();
		}

		long timeNano() {
			auto timePoint = std::chrono::high_resolution_clock::now();
			std::chrono::nanoseconds time = std::chrono::duration_cast<std::chrono::nanoseconds>(timePoint.time_since_epoch());
			return time.count();
		}
	}
}
