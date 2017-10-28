#pragma once
#include <API.h>
#include <backend/Window.h>
#include <Cocoa/Cocoa.h>

@interface CocoaApp : NSApplication {
}
- (void) doNothing:(id) object;
@end

@interface CocoaWindowObj : NSWindow {
}
@end

@interface AppDelegate : NSObject <NSApplicationDelegate>
@end

namespace spruce {
	class CocoaWindow: public Window {
		public:
			CocoaWindowObj* window;
			NSWindowController* windowController;
			NSView* view;
			AppDelegate* delegate;

			CocoaWindow(app::API api, uint16 width, uint16 height);
			virtual ~CocoaWindow();

			void setTitle(string title);
			void setVisible(bool visible);
			void setFullscreen(bool fullscreen);
			void close();
	};
}
