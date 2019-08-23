#pragma once
#ifdef __APPLE__
#include <common.h>

namespace spruce {
	enum class MetalCompareFunction {
		NEVER,
		LESS,
		EQUAL,
		LESS_EQUAL,
		GREATER,
		NOT_EQUAL,
		GREATER_EQUAL,
		ALWAYS
	};
}
#endif
