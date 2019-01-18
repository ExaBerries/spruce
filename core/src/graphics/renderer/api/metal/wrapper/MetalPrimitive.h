#pragma once
#ifdef __APPLE__
#include <common.h>

namespace spruce {
	enum class MetalPrimitive {
		POINT,
		LINE,
		LINE_STRIP,
		TRIANGLE,
		TRIANGLE_STRIP
	};
}
#endif
