#pragma once
#ifdef __APPLE__
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
@end

namespace spruce {
	class CocoaWindow: public Window {
		public:
			CocoaWindowObj* window;
			NSWindowController* windowController;
			NSView* view;
			WindowDelegate* delegate;

			CocoaWindow();
			CocoaWindow(const CocoaWindow&) = delete;
			CocoaWindow(CocoaWindow&&) noexcept = delete;
			~CocoaWindow() override;

			owner<APIContext> initAPI(app::API api) override;
			void setTitle(string title) override;
			void setVisible(bool visible) override;
			void setFullscreen(bool fullscreen) override;
			void close() override;
			void setCursorMode(input::CursorMode mode) override;

			CocoaWindow& operator=(const CocoaWindow&) = delete;
			CocoaWindow& operator=(CocoaWindow&&) noexcept = delete;
	};
}
#endif
