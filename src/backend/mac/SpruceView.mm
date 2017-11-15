#include <backend/mac/SpruceView.h>
#include <backend/Window.h>
#include <input/input.h>

@implementation SpruceView
- (instancetype) initWithFrame:(NSRect)frameRect window:(spruce::CocoaWindow*)_spruceWindow {
	spruceWindow = _spruceWindow;
	self = [super initWithFrame:frameRect];
	[self updateTrackingAreas];
	virtualMousePos = spruce::vec2f(0.5, 0.5);
	return self;
}

- (void) dealloc {
	[trackingArea release];
	[super dealloc];
}

- (void) updateTrackingAreas {
	if (trackingArea != nil) {
		[self removeTrackingArea:trackingArea];
		[trackingArea release];
	}
	const NSTrackingAreaOptions options = NSTrackingMouseEnteredAndExited | NSTrackingMouseMoved | NSTrackingActiveInKeyWindow | NSTrackingEnabledDuringMouseDrag | NSTrackingCursorUpdate | NSTrackingInVisibleRect | NSTrackingAssumeInside;
	trackingArea = [[NSTrackingArea alloc] initWithRect:[self bounds] options:options owner:self userInfo:nil];
	[self addTrackingArea:trackingArea];
	[super updateTrackingAreas];
}

- (void) handleMouseMove:(NSEvent*)event {
	NSPoint pos = [event locationInWindow];
	CGSize frameSize = self.frame.size;
	if (spruceWindow->cursorMode == spruce::input::DISABLED) {
		virtualMousePos += spruce::vec2f([event deltaX] / frameSize.width, [event deltaY] / frameSize.height);
		NSRect local = NSMakeRect(frameSize.width / 2, frameSize.height / 2, 0, 0);
		NSRect global = [spruceWindow->window convertRectToScreen:local];
		NSPoint point = global.origin;
		CGWarpMouseCursorPosition(CGPointMake(point.x, point.y));
	} else {
		virtualMousePos = spruce::vec2f((pos.x / frameSize.width) - 0.5, (pos.y / frameSize.height) - 0.5);
	}
	for (uint16 i = 0; i < spruce::input::processors.size(); i++) {
		spruce::input::processors[i]->mouseMove(virtualMousePos);
	}
}

- (void) keyDown:(NSEvent*)event {
	uint16 keyCode = [event keyCode];
	for (uint16 i = 0; i < spruce::input::processors.size(); i++) {
		spruce::input::processors[i]->keyDown(keyCode);
	}
}

- (void) keyUp:(NSEvent*)event {
	uint16 keyCode = [event keyCode];
	for (uint16 i = 0; i < spruce::input::processors.size(); i++) {
		spruce::input::processors[i]->keyUp(keyCode);
	}
}

- (void) mouseMoved:(NSEvent*)event {
	[self handleMouseMove:event];
}

- (void) mouseDown:(NSEvent*)event {
	for (uint16 i = 0; i < spruce::input::processors.size(); i++) {
		spruce::input::processors[i]->mouseDown(spruce::input::LEFT);
	}
}

- (void) mouseUp:(NSEvent*)event {
	for (uint16 i = 0; i < spruce::input::processors.size(); i++) {
		spruce::input::processors[i]->mouseUp(spruce::input::LEFT);
	}
}

- (void) mouseDragged:(NSEvent*)event {
	[self handleMouseMove:event];
}

- (void) rightMouseDown:(NSEvent*)event {
	for (uint16 i = 0; i < spruce::input::processors.size(); i++) {
		spruce::input::processors[i]->mouseDown(spruce::input::RIGHT);
	}
}

- (void) rightMouseUp:(NSEvent*)event {
	for (uint16 i = 0; i < spruce::input::processors.size(); i++) {
		spruce::input::processors[i]->mouseUp(spruce::input::RIGHT);
	}
}

- (void) rightMouseDragged:(NSEvent*)event {
	[self handleMouseMove:event];
}
@end