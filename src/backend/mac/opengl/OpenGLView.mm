#include <backend/mac/opengl/OpenGLView.h>
#include <OpenGL/gl.h>
#include <OpenGL/gl3.h>
#include <log.h>

@implementation OpenGLView
- (id) initWithFrame:(NSRect)frameRect window:(spruce::CocoaWindow*)_window {
	self = [super initWithFrame:frameRect window:_window];
	return self;
}

- (void) dealloc {
	[[NSNotificationCenter defaultCenter] removeObserver:self name:NSViewGlobalFrameDidChangeNotification object:self];
	[pixelFormat release];
	[NSOpenGLContext clearCurrentContext];
	[context release];
	[super dealloc];
}

- (void) initContext {
	NSOpenGLPixelFormatAttribute attributes[] = {
		NSOpenGLPFAAccelerated,
		NSOpenGLPFAClosestPolicy,
		NSOpenGLPFAOpenGLProfile, NSOpenGLProfileVersion3_2Core,
		NSOpenGLPFAColorSize, 24,
		NSOpenGLPFAAlphaSize, 8,
		NSOpenGLPFADepthSize, 24,
		NSOpenGLPFAStencilSize, 8,
		NSOpenGLPFADoubleBuffer,
		0
	};
	pixelFormat = [[NSOpenGLPixelFormat alloc] initWithAttributes:attributes];
	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(surfaceNeedsUpdate:) name:NSViewGlobalFrameDidChangeNotification object:self];
	context = [[NSOpenGLContext alloc] initWithFormat: pixelFormat shareContext: nil];
	if (context == nullptr) {
		serr("could not create OpenGL context");
		exit(EXIT_FAILURE);
	}
	[context setView: self];
	[self setWantsBestResolutionOpenGLSurface:YES];
}

- (void) update {
	if ([context view] == self) {
		[context update];
	}
}

- (void) surfaceNeedsUpdate:(NSNotification*)notification {
	[self update];
}

- (BOOL) canBecomeKeyView {
	return YES;
}

- (BOOL) wantsUpdateLayer {
	return YES;
}

- (BOOL) acceptsFirstRelationShip {
	return YES;
}

- (NSOpenGLContext*) getContext {
	return context;
}
@end
