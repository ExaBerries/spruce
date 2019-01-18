#pragma once
#ifdef __APPLE__

namespace spruce {
	enum class MetalStorageMode {
		STORAGE_MODE_SHARED,
		STORAGE_MODE_MANAGED,
		STORAGE_MODE_PRIVATE
	};
}
#endif
