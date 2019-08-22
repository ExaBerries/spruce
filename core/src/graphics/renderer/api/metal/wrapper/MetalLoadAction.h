#pragma once
#ifdef __APPLE__
#include <common.h>

namespace spruce {
	enum class MetalLoadAction {
		DONT_CARE,
		LOAD,
		CLEAR
	};
}
#endif
