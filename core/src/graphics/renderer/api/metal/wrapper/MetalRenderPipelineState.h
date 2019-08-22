#pragma once
#ifdef __APPLE__
#include <graphics/renderer/api/metal/wrapper/MetalObj.h>

namespace spruce {
	class MetalRenderPipelineState : public MetalObj {
		public:
			MetalRenderPipelineState(void* ptr);
			~MetalRenderPipelineState();
	};
}
#endif
