#pragma once
#include <graphics/RenderTarget.h>
#include <backend/api/metal/MetalTexture.h>
#include <backend/api/metal/MetalContext.h>
#include <Metal/Metal.h>

namespace spruce {
	class MetalRenderTarget : public RenderTarget {
		public:
			MetalContext& context;
			MetalTexture* color;
			MetalTexture* depth;
			MTLRenderPassDescriptor* renderPassDescriptor;

			MetalRenderTarget(MetalContext& context);
			MetalRenderTarget(Texture::PixelFormat format, uint16 width, uint16 height, MetalContext& context);
			MetalRenderTarget(const MetalRenderTarget& renderTarget) = delete;
			virtual ~MetalRenderTarget();
	};
}
