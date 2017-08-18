#pragma once
#include <common.h>

namespace spruce {
	namespace system {
		string getCPUName();
		uint16 getCPUCoreCount();
		uint16 getCPUThreadCount();
	}
}
