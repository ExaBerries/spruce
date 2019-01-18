#include <graphics/renderer/api/metal/wrapper/MetalTexture.h>
#ifdef __APPLE__

namespace spruce {
	MetalTexture::MetalTexture(void* ptr) : MetalObj(ptr) {
	}

	MetalTexture::~MetalTexture() {
	}

}
#endif
