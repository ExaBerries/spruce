#include <graphics/renderer/api/metal/wrapper/MetalRenderPipelineState.h>
#ifdef __APPLE__

namespace spruce {
	MetalRenderPipelineState::MetalRenderPipelineState(void* ptr) : MetalObj(ptr) {
	}

	MetalRenderPipelineState::~MetalRenderPipelineState() {
	}
}
#endif
