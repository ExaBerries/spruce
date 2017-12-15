#pragma once
#include <graphics/RenderTarget.h>
#include <graphics/RenderBuffer.h>
#include <backend/api/metal/MetalTexture.h>
#include <Metal/Metal.h>

namespace spruce {
	class MetalRenderTarget : public RenderTarget {
		public:
			MetalTexture* color;
			MetalTexture* depth;
			MTLRenderPassDescriptor* renderPassDescriptor;

			MetalRenderTarget(Texture::PixelFormat format, uint16 width, uint16 height);
			virtual ~MetalRenderTarget();

			void bind();
	};
}
