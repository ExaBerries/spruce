#include <backend/mac/metal/MetalSurface.h>
#include <backend/api/metal/MetalContext.h>
#include <backend/api/metal/MetalRenderTarget.h>
#include <graphics/graphics.h>

namespace spruce {
	MetalSurface::MetalSurface(MetalView* view, MetalContext* context) {
		this->view = view;
		this->context = context;
		this->target = new MetalRenderTarget(*context);
		drawable = [view getDrawable];
		MTLTextureDescriptor* desc = [MTLTextureDescriptor texture2DDescriptorWithPixelFormat:MTLPixelFormatDepth32Float width:spruce::graphics::width height:spruce::graphics::height mipmapped:NO];
		desc.resourceOptions = MTLResourceStorageModePrivate;
		desc.storageMode = MTLStorageModePrivate;
		desc.usage = MTLTextureUsageRenderTarget | MTLTextureUsageShaderRead;
		depthTexture = [context->device newTextureWithDescriptor:desc];
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
		context->commandBuffer = [context->commandQueue commandBuffer];
		[context->commandBuffer enqueue];
		[view update];
		drawable = [view getDrawable];
		[depthTexture release];
		MTLTextureDescriptor* desc = [MTLTextureDescriptor texture2DDescriptorWithPixelFormat:MTLPixelFormatDepth32Float width:spruce::graphics::width height:spruce::graphics::height mipmapped:NO];
		desc.resourceOptions = MTLResourceStorageModePrivate;
		desc.storageMode = MTLStorageModePrivate;
		desc.usage = MTLTextureUsageRenderTarget | MTLTextureUsageShaderRead;
		depthTexture = [context->device newTextureWithDescriptor:desc];
		[desc release];
		renderPassDesc.colorAttachments[0].texture = drawable.texture;
		renderPassDesc.colorAttachments[0].loadAction = MTLLoadActionClear;
		renderPassDesc.colorAttachments[0].storeAction = MTLStoreActionStore;
		renderPassDesc.colorAttachments[0].clearColor = MTLClearColorMake(0.0, 0.0, 0.0, 1.0);
		renderPassDesc.depthAttachment.texture = depthTexture;
		renderPassDesc.depthAttachment.loadAction = MTLLoadActionClear;
		renderPassDesc.depthAttachment.storeAction = MTLStoreActionStore;
		renderPassDesc.depthAttachment.clearDepth = 1.0;
		context->renderEncoder = [context->commandBuffer renderCommandEncoderWithDescriptor:renderPassDesc];
		context->renderEncoder.label = @"SpruceRenderEncoder";
		[context->renderEncoder setViewport:(MTLViewport){0.0, 0.0, (double)drawable.texture.width, (double)drawable.texture.height, 0.0, 1.0}];
		[context->renderEncoder setDepthStencilState:context->depthStencilState];
	}

	void MetalSurface::renderEnd() {
		if (context->renderEncoder == nullptr) {
			return;
		}
		[context->renderEncoder endEncoding];
		if (drawable != nil) {
			[context->commandBuffer presentDrawable:drawable];
		} else {
			serr("drawable is nil");
		}
		[context->commandBuffer commit];
		[drawable release];
		[context->commandBuffer release];
		[context->renderEncoder release];
	}
}
