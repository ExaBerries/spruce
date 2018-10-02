#include <backend/mac/metal/MetalSurface.h>
#include <backend/api/metal/MetalContext.h>
#include <backend/api/metal/MetalRenderTarget.h>
#include <graphics/graphics.h>

namespace spruce {
	MetalSurface::MetalSurface(MetalView* view) {
		this->view = view;
		this->target = new MetalRenderTarget();
		drawable = [view getDrawable];
		MTLTextureDescriptor* desc = [MTLTextureDescriptor texture2DDescriptorWithPixelFormat:MTLPixelFormatDepth32Float width:spruce::graphics::width height:spruce::graphics::height mipmapped:NO];
		desc.resourceOptions = MTLResourceStorageModePrivate;
		desc.storageMode = MTLStorageModePrivate;
		desc.usage = MTLTextureUsageRenderTarget | MTLTextureUsageShaderRead;
		depthTexture = [spruce::device newTextureWithDescriptor:desc];
		renderPassDesc = [MTLRenderPassDescriptor renderPassDescriptor];
		renderPassDesc.colorAttachments[0].texture = drawable.texture;
		renderPassDesc.colorAttachments[0].loadAction = MTLLoadActionClear;
		renderPassDesc.colorAttachments[0].storeAction = MTLStoreActionStore;
		renderPassDesc.colorAttachments[0].clearColor = MTLClearColorMake(0.0, 0.0, 0.0, 1.0);
		renderPassDesc.depthAttachment.texture = depthTexture;
		renderPassDesc.depthAttachment.loadAction = MTLLoadActionClear;
		renderPassDesc.depthAttachment.storeAction = MTLStoreActionStore;
		renderPassDesc.depthAttachment.clearDepth = 1.0;
		((MetalRenderTarget*)this->target)->renderPassDescriptor = renderPassDesc;
	}

	MetalSurface::~MetalSurface() {
		[drawable release];
		[depthTexture release];
	}

	void MetalSurface::renderStart() {
		commandBuffer = [commandQueue commandBuffer];
		[commandBuffer enqueue];
		[view update];
		drawable = [view getDrawable];
		[depthTexture release];
		MTLTextureDescriptor* desc = [MTLTextureDescriptor texture2DDescriptorWithPixelFormat:MTLPixelFormatDepth32Float width:spruce::graphics::width height:spruce::graphics::height mipmapped:NO];
		desc.resourceOptions = MTLResourceStorageModePrivate;
		desc.storageMode = MTLStorageModePrivate;
		desc.usage = MTLTextureUsageRenderTarget | MTLTextureUsageShaderRead;
		depthTexture = [spruce::device newTextureWithDescriptor:desc];
		[desc release];
		renderPassDesc.colorAttachments[0].texture = drawable.texture;
		renderPassDesc.colorAttachments[0].loadAction = MTLLoadActionClear;
		renderPassDesc.colorAttachments[0].storeAction = MTLStoreActionStore;
		renderPassDesc.colorAttachments[0].clearColor = MTLClearColorMake(0.0, 0.0, 0.0, 1.0);
		renderPassDesc.depthAttachment.texture = depthTexture;
		renderPassDesc.depthAttachment.loadAction = MTLLoadActionClear;
		renderPassDesc.depthAttachment.storeAction = MTLStoreActionStore;
		renderPassDesc.depthAttachment.clearDepth = 1.0;
		renderEncoder = [commandBuffer renderCommandEncoderWithDescriptor:renderPassDesc];
		renderEncoder.label = @"SpruceRenderEncoder";
		[renderEncoder setViewport:(MTLViewport){0.0, 0.0, (double)drawable.texture.width, (double)drawable.texture.height, 0.0, 1.0}];
		[renderEncoder setDepthStencilState:depthStencilState];
	}

	void MetalSurface::renderEnd() {
		[renderEncoder endEncoding];
		if (drawable != nil) {
			[commandBuffer presentDrawable:drawable];
		} else {
			serr("drawable is nil");
		}
		[commandBuffer commit];
		[drawable release];
		[commandBuffer release];
		[renderEncoder release];
	}
}
