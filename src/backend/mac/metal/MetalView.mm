#include <backend/mac/metal/MetalView.h>
#include <backend/api/metal/MetalContext.h>
#include <log.h>
#include <graphics/graphics.h>

@implementation MetalView
- (id) initWithFrame:(NSRect)frame window:(spruce::CocoaWindow*)_window {
	self = [super initWithFrame:frame window:_window];
	[self setWantsLayer:YES];
	return self;
}

- (CALayer*) makeBackingLayer {
	mlayer = [[CAMetalLayer alloc] init];
	mlayer.device = spruce::device;
	mlayer.pixelFormat = MTLPixelFormatBGRA8Unorm;
	mlayer.colorspace = CGColorSpaceCreateDeviceRGB();
	mlayer.wantsExtendedDynamicRangeContent = YES;
	if (spruce::graphics::vsync) {
		mlayer.displaySyncEnabled = YES;
	} else {
		mlayer.displaySyncEnabled = NO;
	}
	mlayer.framebufferOnly = YES;
	mlayer.drawableSize = CGSizeMake(spruce::graphics::width, spruce::graphics::height);
	mlayer.magnificationFilter = kCAFilterNearest;
	self.layer = mlayer;
	MTLTextureDescriptor* desc = [MTLTextureDescriptor texture2DDescriptorWithPixelFormat:MTLPixelFormatDepth32Float width:spruce::graphics::width height:spruce::graphics::height mipmapped:NO];
	desc.resourceOptions = MTLResourceStorageModePrivate;
	desc.storageMode = MTLStorageModePrivate;
	desc.usage = MTLTextureUsageRenderTarget | MTLTextureUsageShaderRead;
	depthTexture = [spruce::device newTextureWithDescriptor:desc];
	return mlayer;
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
	mlayer.drawableSize = CGSizeMake(spruce::graphics::width, spruce::graphics::height);
	if (spruce::graphics::vsync) {
		mlayer.displaySyncEnabled = YES;
	} else {
		mlayer.displaySyncEnabled = NO;
	}
	MTLTextureDescriptor* desc = [MTLTextureDescriptor texture2DDescriptorWithPixelFormat:MTLPixelFormatDepth32Float width:spruce::graphics::width height:spruce::graphics::height mipmapped:NO];
	desc.resourceOptions = MTLResourceStorageModePrivate;
	desc.storageMode = MTLStorageModePrivate;
	desc.usage = MTLTextureUsageRenderTarget | MTLTextureUsageShaderRead;
	depthTexture = [spruce::device newTextureWithDescriptor:desc];
	drawable = [mlayer nextDrawable];
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
