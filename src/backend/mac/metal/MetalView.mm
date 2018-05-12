#include <backend/mac/metal/MetalView.h>
#include <backend/api/metal/MetalContext.h>
#include <log.h>

@implementation MetalView
- (id) initWithFrame:(NSRect)frame window:(spruce::CocoaWindow*)_window {
	self = [super initWithFrame:frame window:_window];
	[self setWantsLayer:YES];
	return self;
}

- (CALayer*) makeBackingLayer {
	uint16 width = self.frame.size.width;
	uint16 height = self.frame.size.height;
	CAMetalLayer* layer = [[CAMetalLayer alloc] init];
	layer.device = spruce::device;
	layer.pixelFormat = MTLPixelFormatBGRA8Unorm;
	layer.colorspace = CGColorSpaceCreateDeviceRGB();
	layer.wantsExtendedDynamicRangeContent = YES;
	layer.displaySyncEnabled = YES;
	layer.framebufferOnly = YES;
	layer.drawableSize = CGSizeMake(width, height);
	self.layer = layer;
	MTLTextureDescriptor* desc = [MTLTextureDescriptor texture2DDescriptorWithPixelFormat:MTLPixelFormatDepth32Float width:width height:height mipmapped:NO];
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

- (CGSize) getDrawableSize {
	return ((CAMetalLayer*)self.layer).drawableSize;
}
@end
