#pragma once
#include <API.h>
#include <backend/Window.h>
#include <Cocoa/Cocoa.h>

@interface CocoaWindowObj : NSWindow {
}
@end

@interface WindowDelegate : NSObject <NSWindowDelegate> {
	spruce::Window* spruceWindow;
	CocoaWindowObj* cocoaWindow;
}
- (instancetype) initWithWindow:(spruce::Window*)spruceWindow cocoaWindow:(NSWindow*)cocoaWindow;
//- (void) windowDidResize:(NSNotification*)notification;
@end

namespace spruce {
	class CocoaWindow: public Window {
		public:
			CocoaWindowObj* window;
			NSWindowController* windowController;
			NSView* view;
			WindowDelegate* delegate;

			CocoaWindow();
			virtual ~CocoaWindow();

			void initSurface(app::API api);
			void setTitle(string title);
			void setVisible(bool visible);
			void setFullscreen(bool fullscreen);
			void close();
			void setCursorMode(input::CursorMode mode);
	};
}
