#pragma once
#import <Cocoa/Cocoa.h>
#import <Metal/Metal.h>
#import <MetalKit/MetalKit.h>
#import <QuartzCore/QuartzCore.h>
#import <Metal/MTLDrawable.h>

@interface MetalView : NSView {
	id<MTLTexture> depthTexture;
	id<CAMetalDrawable> drawable;
	MTLRenderPassDescriptor* renderPassDescriptor;
}
- (id) initWithFrame:(NSRect)frame;
- (void) update;
- (id<CAMetalDrawable>) getDrawable;
- (MTLRenderPassDescriptor*) getRenderPassDescriptor;
- (void) releaseDrawable;
- (MTLPixelFormat) getDepthPixelFormat;
@end
