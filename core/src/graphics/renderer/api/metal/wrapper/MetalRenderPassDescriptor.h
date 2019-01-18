#pragma once
#ifdef __APPLE__
#include <common.h>
#include <graphics/renderer/api/metal/wrapper/MetalObj.h>

namespace spruce {
	class MetalRenderPassDescriptor : public MetalObj {
		public:
			MetalRenderPassDescriptor();
			~MetalRenderPassDescriptor();
	};
}
#endif
