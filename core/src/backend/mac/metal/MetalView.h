#pragma once
#ifdef __APPLE__
#import <backend/mac/SpruceView.h>
#import <Cocoa/Cocoa.h>
#import <Metal/Metal.h>
#import <QuartzCore/QuartzCore.h>
#import <Metal/MTLDrawable.h>
#include <task/semaphore.h>

@interface MetalView : SpruceView {
	CAMetalLayer* mlayer;
}
- (id) initWithFrame:(NSRect)frame window:(spruce::CocoaWindow*)window;
- (void) setDevice:(id<MTLDevice>)device;
- (void) update;
- (id<CAMetalDrawable>) getDrawable;
@end
#endif
