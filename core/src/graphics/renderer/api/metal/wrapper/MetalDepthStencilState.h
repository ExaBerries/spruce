#pragma once
#ifdef __APPLE__
#include <common.h>
#include <graphics/renderer/api/metal/wrapper/MetalObj.h>

namespace spruce {
	class MetalDepthStencilState : public MetalObj {
		public:
			MetalDepthStencilState(void* ptr);
			MetalDepthStencilState(const MetalDepthStencilState& other) = delete;
			MetalDepthStencilState(MetalDepthStencilState&& other) = delete;
			~MetalDepthStencilState();

			MetalDepthStencilState& operator=(const MetalDepthStencilState& other) = delete;
			MetalDepthStencilState& operator=(MetalDepthStencilState&& other) = delete;
	};
}
#endif
