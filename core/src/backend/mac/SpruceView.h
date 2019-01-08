#pragma once
#ifdef __APPLE__
#include <backend/mac/CocoaWindow.h>
#import <Cocoa/Cocoa.h>

@interface SpruceView : NSView {
	spruce::CocoaWindow* spruceWindow;
	spruce::vec2f virtualMousePos;
	NSTrackingArea* trackingArea;
	std::map<uint16, bool> modifiers;
}
- (instancetype) initWithFrame:(NSRect)frameRect window:(spruce::CocoaWindow*)window;
@end
#endif