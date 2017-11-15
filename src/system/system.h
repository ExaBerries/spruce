#pragma once
#include <common.h>

namespace spruce {
	namespace sys {
		string getCPUName();
		uint16 getCPUCoreCount();
		uint16 getCPUThreadCount();

		float timeSec();
		long timeNano();
	}
}
