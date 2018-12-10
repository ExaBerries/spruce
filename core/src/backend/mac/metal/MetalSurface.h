#pragma once
#include <common.h>
#include <backend/RenderSurface.h>
#include <backend/mac/metal/MetalView.h>
#include <backend/api/metal/MetalContext.h>

namespace spruce {
	class MetalSurface : public RenderSurface {
		public:
			MetalView* view;
			MTLRenderPassDescriptor* renderPassDesc;
			id<CAMetalDrawable> drawable;
			id<MTLTexture> depthTexture;
			MetalContext* context;

			MetalSurface(MetalView* view, MetalContext* context);
			virtual ~MetalSurface();

			void renderStart();
			void renderEnd();
	};
}
