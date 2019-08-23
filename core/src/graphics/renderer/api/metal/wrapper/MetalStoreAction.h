#pragma once
#ifdef __APPLE__
#include <common.h>

namespace spruce {
	enum class MetalStoreAction {
		DONT_CARE,
		STORE,
		MULTISAMPLE_RESOLVE,
		STORE_AND_MULTISAMPLE_RESOLVE,
		UNKNOWN,
		CUSTOM_SAMPLE_DEPTH_STORE
	};
}
#endif
