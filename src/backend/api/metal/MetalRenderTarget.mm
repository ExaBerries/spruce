#include <backend/api/metal/MetalRenderTarget.h>

namespace spruce {
	MetalRenderTarget::MetalRenderTarget(Texture::PixelFormat format, uint16 width, uint16 height) : RenderTarget(width, height) {
		renderPassDescriptor = [MTLRenderPassDescriptor renderPassDescriptor];
		if (format != Texture::DEPTH) {
			color = new MetalTexture(format, nullptr, width, height);
			color->toVRAM();
			renderPassDescriptor.colorAttachments[0].texture = color->mtlTexture;
			renderPassDescriptor.colorAttachments[0].loadAction = MTLLoadActionClear;
			renderPassDescriptor.colorAttachments[0].storeAction = MTLStoreActionStore;
			renderPassDescriptor.colorAttachments[0].clearColor = MTLClearColorMake(0.0, 0.0, 0.0, 1.0);
		} else {
			color = nullptr;
		}
		depth = new MetalTexture(Texture::DEPTH, nullptr, width, height);
		depth->toVRAM();
		renderPassDescriptor.depthAttachment.texture = this->depth->mtlTexture;
		renderPassDescriptor.depthAttachment.loadAction = MTLLoadActionClear;
		renderPassDescriptor.depthAttachment.storeAction = MTLStoreActionStore;
		renderPassDescriptor.depthAttachment.clearDepth = 1.0;
	}

	MetalRenderTarget::~MetalRenderTarget() {
		if (color != nullptr) {
			delete color;
		}
		if (depth != nullptr) {
			delete depth;
		}
		[renderPassDescriptor release];
	}

	void MetalRenderTarget::bind() {
	}
}