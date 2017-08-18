#include <system/system.h>
#include <thread>

namespace spruce {
	namespace system {
		uint16 getCPUThreadCount() {
			return std::thread::hardware_concurrency();
		}
	}
}
