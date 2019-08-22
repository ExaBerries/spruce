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
}
- (id) initWithFrame:(NSRect)frame window:(spruce::CocoaWindow*)window;
- (void) setDevice:(id<MTLDevice>)device;
- (id<CAMetalDrawable>) getDrawable;
- (void)setDrawableSize:(spruce::vec2i)drawableSize;
- (void)setVSync:(bool)vsync;
@end
#endif
