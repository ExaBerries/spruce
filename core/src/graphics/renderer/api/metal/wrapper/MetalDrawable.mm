#include <graphics/renderer/api/metal/wrapper/MetalDrawable.h>
#ifdef __APPLE__

namespace spruce {
	MetalDrawable::MetalDrawable(void* ptr) : MetalObj(ptr) {
	}

	MetalDrawable::~MetalDrawable() {
	}
}
#endif
