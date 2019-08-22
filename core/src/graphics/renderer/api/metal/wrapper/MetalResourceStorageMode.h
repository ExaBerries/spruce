#pragma once
#ifdef __APPLE__
#include <common.h>

namespace spruce {
	enum class MetalResourceStorageMode {
		SHARED,
		MANAGED,
		PRIVATE
	};
}
#endif
