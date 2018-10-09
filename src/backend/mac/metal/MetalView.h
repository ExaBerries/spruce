#pragma once
#import <backend/mac/SpruceView.h>
#import <Cocoa/Cocoa.h>
#import <Metal/Metal.h>
#import <QuartzCore/QuartzCore.h>
#import <Metal/MTLDrawable.h>
#include <task/semaphore.h>
#include <backend/api/metal/MetalContext.h>

@interface MetalView : SpruceView {
	CAMetalLayer* mlayer;
	spruce::MetalContext* context;
}
- (id) initWithFrame:(NSRect)frame window:(spruce::CocoaWindow*)window;
- (void) update;
- (id<CAMetalDrawable>) getDrawable;
@end
