#pragma once
#include <common.h>
#include <system/time.h>

namespace spruce {
	namespace sys {
		[[nodiscard]] string getSystemInfo();
		[[nodiscard]] string getCPUName();
		[[nodiscard]] uint16 getCPUCoreCount();
		[[nodiscard]] uint16 getCPUThreadCount();
		[[nodiscard]] uint64 getCPUFrequency();
		[[nodiscard]] uint64 getCacheLineSize();
		[[nodiscard]] uint64 getL1CacheSize();
		[[nodiscard]] uint64 getL2CacheSize();
		[[nodiscard]] uint64 getL3CacheSize();
		[[nodiscard]] uint64 getRAMSize();
		[[nodiscard]] uint64 getSwapUsed();
	}
}
