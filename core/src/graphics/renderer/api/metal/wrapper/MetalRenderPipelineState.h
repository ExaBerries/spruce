#pragma once
#ifdef __APPLE__
#include <graphics/renderer/api/metal/wrapper/MetalObj.h>

namespace spruce {
	class MetalRenderPipelineState : public MetalObj {
		public:
			MetalRenderPipelineState(void* ptr);
			MetalRenderPipelineState(const MetalRenderPipelineState&) = delete;
			MetalRenderPipelineState(MetalRenderPipelineState&&) noexcept = delete;
			~MetalRenderPipelineState() override = default;

			MetalRenderPipelineState& operator=(const MetalRenderPipelineState&) = delete;
			MetalRenderPipelineState& operator=(MetalRenderPipelineState&&) noexcept = delete;
	};
}
#endif
