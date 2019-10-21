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

			[[nodiscard]] owner<APIContext> initAPI(app::API api) noexcept override;
			void setTitle(string title) noexcept override;
			void setVisible(bool visible) noexcept override;
			void setFullscreen(bool fullscreen) noexcept override;
			void close() noexcept override;
			void setCursorMode(input::CursorMode mode) noexcept override;

			CocoaWindow& operator=(const CocoaWindow&) = delete;
			CocoaWindow& operator=(CocoaWindow&&) noexcept = delete;
	};
}
#endif
