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

			void createXWindow(Visual* visual, uint32 depth) noexcept;

			[[nodiscard]] owner<APIContext> initAPI(app::API api) noexcept override;
			void setTitle(string title) noexcept override;
			void setVisible(bool visible) noexcept override;
			void setFullscreen(bool fullscreen) noexcept override;
			void close() noexcept override;
			void setCursorMode(input::CursorMode mode) noexcept override;

			X11Window& operator=(const X11Window&) = delete;
			X11Window& operator=(X11Window&&) noexcept = delete;
	};
}
#endif
