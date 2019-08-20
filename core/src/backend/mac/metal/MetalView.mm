#ifdef __APPLE__
#include <backend/mac/metal/MetalView.h>
#include <log.h>

@implementation MetalView
- (id) initWithFrame:(NSRect)frame window:(spruce::CocoaWindow*)_window {
	self = [super initWithFrame:frame window:_window];
	[self setWantsLayer:YES];
	return self;
}

- (CALayer*) makeBackingLayer {
	mlayer = [[CAMetalLayer alloc] init];
	mlayer.pixelFormat = MTLPixelFormatBGRA8Unorm;
	mlayer.colorspace = CGColorSpaceCreateDeviceRGB();
	mlayer.wantsExtendedDynamicRangeContent = YES;
	if (vsync) {
		mlayer.displaySyncEnabled = YES;
	} else {
		mlayer.displaySyncEnabled = NO;
	}
	mlayer.framebufferOnly = YES;
	mlayer.drawableSize = CGSizeMake(drawableSize.x, drawableSize.y);
	mlayer.magnificationFilter = kCAFilterNearest;
	self.layer = mlayer;
	return mlayer;
}

- (void) dealloc {
	[super dealloc];
}

- (BOOL) wantsLayer {
	return YES;
}

- (BOOL) wantsUpdateLayer {
	return YES;
}

- (void) setDevice:(id<MTLDevice>)device {
	mlayer.device = device;
}

- (void) update {
	mlayer.drawableSize = CGSizeMake(drawableSize.x, drawableSize.y);
	if (vsync) {
		mlayer.displaySyncEnabled = YES;
	} else {
		mlayer.displaySyncEnabled = NO;
	}
}

- (id<CAMetalDrawable>) getDrawable {
	return [mlayer nextDrawable];
}

- (void)setDrawableSize:(spruce::vec2i)newDrawableSize {
	drawableSize = newDrawableSize;
}

- (void)setVSync:(bool)newVSync {
	vsync = newVSync;
}
@end
#endif
