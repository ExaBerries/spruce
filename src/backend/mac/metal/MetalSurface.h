#pragma once
#include <common.h>
#include <backend/RenderSurface.h>
#include <backend/mac/metal/MetalView.h>

namespace spruce {
	class MetalSurface : public RenderSurface {
		public:
			MetalView* view;
			MTLRenderPassDescriptor* renderPassDesc;
			id<CAMetalDrawable> drawable;
			id<MTLTexture> depthTexture;

			MetalSurface(MetalView* view);
			virtual ~MetalSurface();

			void renderStart();
			void renderEnd();
	};
}
