#pragma once
#ifdef __APPLE__
#include <common.h>

namespace spruce {
	enum class MetalVertexStepFunction {
		CONSTANT,
		PER_VERTEX,
		PER_INSTANCE,
		PER_PATCH,
		PER_PATCH_CONTROL_POINT
	};
}
#endif
