#include <common.h>
#include <system/system.h>
#include <sys/sysctl.h>

namespace spruce {
	namespace system {
		string getCPUName() {
			size_t length = 128;
			char buffer[length];
			sysctlbyname("machdep.cpu.brand_string", &buffer, &length, NULL, 0);
			return string(buffer);
		}

		uint16 getCPUCoreCount() {
			size_t size = sizeof(uint16);
			uint16 coreCount = 0;
			sysctlbyname("machdep.cpu.core_count", &coreCount, &size, NULL, 0);
			return coreCount;
		}
	}
}
