#pragma once
#ifdef __APPLE__
#import <backend/mac/SpruceView.h>
#import <Cocoa/Cocoa.h>
#import <OpenGL/OpenGL.h>

@interface OpenGLView : SpruceView {
	NSOpenGLContext* context;
	NSOpenGLPixelFormat* pixelFormat;
}
- (id) initWithFrame:(NSRect)bounds window:(spruce::CocoaWindow*)cocoaWindow;
- (void) initContext;
- (void) update;
- (NSOpenGLContext*) getContext;
@end
#endif
