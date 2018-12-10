#include <backend/mac/metal/MetalView.h>
#include <backend/api/metal/MetalContext.h>
#include <log.h>
#include <graphics/graphics.h>

@implementation MetalView
- (id) initWithFrame:(NSRect)frame window:(spruce::CocoaWindow*)_window context:(spruce::MetalContext*)_context {
	self = [super initWithFrame:frame window:_window];
	context = _context;
	[self setWantsLayer:YES];
	return self;
}

- (CALayer*) makeBackingLayer {
	mlayer = [[CAMetalLayer alloc] init];
	mlayer.device = context->device;
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
	return mlayer;
}

- (void) dealloc {
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
}

- (id<CAMetalDrawable>) getDrawable {
	return [mlayer nextDrawable];
}
@end
