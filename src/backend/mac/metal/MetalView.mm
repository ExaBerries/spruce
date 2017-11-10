#include <backend/mac/metal/MetalView.h>
#include <backend/api/metal/MetalContext.h>
#include <log.h>

@implementation MetalView
- (id) initWithFrame:(NSRect)frame {
	self = [super initWithFrame:frame];
	[self setWantsLayer:YES];
	return self;
}

- (CALayer*) makeBackingLayer {
	CAMetalLayer* layer = [[CAMetalLayer alloc] init];
	layer.device = spruce::device;
	layer.pixelFormat = MTLPixelFormatBGRA8Unorm_sRGB;
	layer.drawableSize = CGSizeMake(1280, 720);
	self.layer = layer;
	MTLTextureDescriptor* desc = [MTLTextureDescriptor texture2DDescriptorWithPixelFormat:MTLPixelFormatDepth32Float width:1280 height:720 mipmapped:NO];
	desc.resourceOptions = MTLResourceStorageModePrivate;
	desc.storageMode = MTLStorageModePrivate;
	desc.usage = MTLTextureUsageRenderTarget | MTLTextureUsageShaderRead;
	depthTexture = [spruce::device newTextureWithDescriptor:desc];
	return layer;
}
- (void) dealloc {
	[depthTexture release];
}

- (BOOL) wantsLayer {
	return YES;
}

- (BOOL) wantsUpdateLayer {
	return YES;
}

- (void) update {
	drawable = [((CAMetalLayer*)self.layer) nextDrawable];
	[renderPassDescriptor release];
	renderPassDescriptor = [MTLRenderPassDescriptor renderPassDescriptor];
	renderPassDescriptor.colorAttachments[0].texture = drawable.texture;
	renderPassDescriptor.colorAttachments[0].loadAction = MTLLoadActionClear;
	renderPassDescriptor.colorAttachments[0].storeAction = MTLStoreActionStore;
	renderPassDescriptor.colorAttachments[0].clearColor = MTLClearColorMake(0.0, 0.0, 0.0, 1.0);
	renderPassDescriptor.depthAttachment.texture = depthTexture;
	renderPassDescriptor.depthAttachment.loadAction = MTLLoadActionClear;
	renderPassDescriptor.depthAttachment.storeAction = MTLStoreActionStore;
	renderPassDescriptor.depthAttachment.clearDepth = 1.0;
}

- (id<CAMetalDrawable>) getDrawable {
	return drawable;
}

- (MTLRenderPassDescriptor*) getRenderPassDescriptor {
	return renderPassDescriptor;
}

- (void) releaseDrawable {
	[drawable release];
}

- (MTLPixelFormat) getDepthPixelFormat {
	return depthTexture.pixelFormat;
}
@end
