#pragma once
#ifdef __APPLE__
#include <common.h>
#import <backend/mac/SpruceView.h>
#import <Cocoa/Cocoa.h>
#import <Metal/Metal.h>
#import <QuartzCore/QuartzCore.h>
#import <Metal/MTLDrawable.h>

@interface MetalView : SpruceView {
	CAMetalLayer* mlayer;
	spruce::vec2i drawableSize;
	bool vsync;
}
- (id) initWithFrame:(NSRect)frame window:(spruce::CocoaWindow*)window;
- (void) setDevice:(id<MTLDevice>)device;
- (void) update;
- (id<CAMetalDrawable>) getDrawable;
- (void)setDrawableSize:(spruce::vec2i)newDrawableSize;
- (void)setVSync:(bool)newVSync;
@end
#endif
