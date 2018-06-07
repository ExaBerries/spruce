#pragma once
#include <common.h>
#include <system/time.h>
#include <system/memory.h>

namespace spruce {
	namespace sys {
		string getSystemInfo();
		string getCPUName();
		uint16 getCPUCoreCount();
		uint16 getCPUThreadCount();
		uint64 getCPUFrequency();
		uint64 getCacheLineSize();
		uint64 getL1CacheSize();
		uint64 getL2CacheSize();
		uint64 getL3CacheSize();
		uint64 getRAMSize();
		uint64 getSwapUsed();
	}
}
