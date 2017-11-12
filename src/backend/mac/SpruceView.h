#pragma once
#include <backend/mac/CocoaWindow.h>
#include <math/vec2f.h>
#import <Cocoa/Cocoa.h>

@interface SpruceView : NSView {
	spruce::CocoaWindow* spruceWindow;
	spruce::vec2f virtualMousePos;
	NSTrackingArea* trackingArea;
}
- (instancetype) initWithFrame:(NSRect)frameRect window:(spruce::CocoaWindow*)window;
@end
