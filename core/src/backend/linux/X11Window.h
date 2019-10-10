#pragma once
#ifdef __linux__
#include <common.h>
#include <backend/Window.h>
#include <X11/X.h>
#include <X11/Xlib.h>

typedef Window XWindow;

namespace spruce {
	class X11Window : public Window {
		public:
			Display* display;
			XWindow root;
			Colormap colormap;
			XSetWindowAttributes setAttributes;
			XWindow window;
			XWindowAttributes attributes;

			X11Window(Display* display);
			X11Window(const X11Window&) = delete;
			X11Window(X11Window&&) noexcept = delete;
			~X11Window();

			void createXWindow(Visual* visual, uint32 depth);

			[[nodiscard]] owner<APIContext> initAPI(app::API api) override;
			void setTitle(string title) override;
			void setVisible(bool visible) override;
			void setFullscreen(bool fullscreen) override;
			void close() override;
			void setCursorMode(input::CursorMode mode) override;

			X11Window& operator=(const X11Window&) = delete;
			X11Window& operator=(X11Window&&) noexcept = delete;
	};
}
#endif
