#pragma once
#ifdef __APPLE__

namespace spruce {
	enum class MetalStorageMode {
		SHARED,
		MANAGED,
		PRIVATE
	};
}
#endif
