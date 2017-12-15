#pragma once
#import <backend/mac/SpruceView.h>
#import <Cocoa/Cocoa.h>
#import <Metal/Metal.h>
#import <QuartzCore/QuartzCore.h>
#import <Metal/MTLDrawable.h>

@interface MetalView : SpruceView {
	id<MTLTexture> depthTexture;
	id<CAMetalDrawable> drawable;
	MTLRenderPassDescriptor* renderPassDescriptor;
}
- (id) initWithFrame:(NSRect)frame window:(spruce::CocoaWindow*)window;
- (void) update;
- (id<CAMetalDrawable>) getDrawable;
- (MTLRenderPassDescriptor*) getRenderPassDescriptor;
- (void) releaseDrawable;
- (MTLPixelFormat) getDepthPixelFormat;
- (CGSize) getDrawableSize;
@end
