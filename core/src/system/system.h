#pragma once
#include <common.h>
#include <system/time.h>

namespace spruce {
	namespace sys {
		[[nodiscard]] string getSystemInfo() noexcept;
		[[nodiscard]] string getCPUName() noexcept;
		[[nodiscard]] uint16 getCPUCoreCount() noexcept;
		[[nodiscard]] uint16 getCPUThreadCount() noexcept;
		[[nodiscard]] uint64 getCPUFrequency() noexcept;
		[[nodiscard]] uint64 getCacheLineSize() noexcept;
		[[nodiscard]] uint64 getL1CacheSize() noexcept;
		[[nodiscard]] uint64 getL2CacheSize() noexcept;
		[[nodiscard]] uint64 getL3CacheSize() noexcept;
		[[nodiscard]] uint64 getRAMSize() noexcept;
		[[nodiscard]] uint64 getSwapUsed() noexcept;
	}
}
