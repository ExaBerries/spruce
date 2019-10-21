#include <system/system.h>
#include <backend/os.h>
#include <thread>

namespace spruce {
	namespace sys {
		string getSystemInfo() noexcept {
			string info;
			info += "Spruce System Info:\n";
			info += "CPU name = " + getCPUName() + "\n";
			info += "CPU core count = " + std::to_string(getCPUCoreCount()) + "\n";
			info += "CPU thread count = " + std::to_string(getCPUThreadCount()) + "\n";
			info += "CPU frequency = " + std::to_string(getCPUFrequency()) + "\n";
			info += "CPU cache line size = " + std::to_string(getCacheLineSize()) + "\n";
			info += "CPU L1 cache size = " + std::to_string(getL1CacheSize()) + "\n";
			info += "CPU L2 cache size = " + std::to_string(getL2CacheSize()) + "\n";
			info += "CPU L3 cache size = " + std::to_string(getL3CacheSize()) + "\n";
			info += "ram size = " + std::to_string(getRAMSize()) + "\n";
			info += "swap used = " + std::to_string(getSwapUsed()) + "\n";
			return info;
		}

		uint16 getCPUThreadCount() noexcept {
			return static_cast<uint16>(std::thread::hardware_concurrency());
		}
	}
}
