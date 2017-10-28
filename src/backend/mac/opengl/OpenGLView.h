#pragma once
#import <Cocoa/Cocoa.h>
#import <OpenGL/OpenGL.h>
#import <OpenGL/gl.h>

@interface OpenGLView : NSView {
	NSOpenGLContext* context;
	NSOpenGLPixelFormat* pixelFormat;
}
- (id) initWithFrame:(NSRect) bounds;
- (void) initContext;
- (void) update;
- (void) drawRect:(NSRect)rect;
- (NSOpenGLContext*) getContext;
@end
