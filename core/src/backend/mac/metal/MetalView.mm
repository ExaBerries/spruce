#ifdef __APPLE__
#include <backend/mac/metal/MetalView.h>
#include <log.h>

@implementation MetalView
- (id) initWithFrame:(NSRect)frame window:(spruce::CocoaWindow*)cocoaWindow {
	self = [super initWithFrame:frame window:cocoaWindow];
	[self setWantsLayer:YES];
	return self;
}

- (CALayer*) makeBackingLayer {
	mlayer = [[CAMetalLayer alloc] init];
	mlayer.pixelFormat = MTLPixelFormatBGRA8Unorm;
	mlayer.colorspace = CGColorSpaceCreateDeviceRGB();
	mlayer.wantsExtendedDynamicRangeContent = YES;
	mlayer.displaySyncEnabled = YES;
	mlayer.framebufferOnly = YES;
	mlayer.drawableSize = CGSizeMake(self.frame.size.width, self.frame.size.height);
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

- (id<CAMetalDrawable>) getDrawable {
	return [mlayer nextDrawable];
}

- (void)setDrawableSize:(spruce::vec2i)drawableSize {
	mlayer.drawableSize = CGSizeMake(drawableSize.x, drawableSize.y);
}

- (void)setVSync:(bool)vsync {
	if (vsync) {
		mlayer.displaySyncEnabled = YES;
	} else {
		mlayer.displaySyncEnabled = NO;
	}
}
@end
#endif
