#include <graphics/renderer/api/metal/wrapper/MetalRenderPassDescriptor.h>
#ifdef __APPLE__
#include <graphics/renderer/api/metal/mtlplatform.h>

namespace spruce {
	MetalRenderPassDescriptor::MetalRenderPassDescriptor() : MetalObj([MTLRenderPassDescriptor renderPassDescriptor]) {
	}

	MetalRenderPassDescriptor::~MetalRenderPassDescriptor() {
	}
}
#endif
