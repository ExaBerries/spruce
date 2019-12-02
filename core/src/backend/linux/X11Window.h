#pragma once
#ifdef __linux__
#include <common.h>
#include <backend/Window.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>

using XWindow = Window;

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
			~X11Window() final;

			void createXWindow(Visual* visual, uint32 depth) noexcept;

			[[nodiscard]] owner<APIContext> initAPI(app::API api) noexcept final;
			void setTitle(string title) noexcept final;
			void setVisible(bool visible) noexcept final;
			void setFullscreen(bool fullscreen) noexcept final;
			void close() noexcept final;
			void setCursorMode(input::CursorMode mode) noexcept final;

			X11Window& operator=(const X11Window&) = delete;
			X11Window& operator=(X11Window&&) noexcept = delete;
	};
}
#endif
