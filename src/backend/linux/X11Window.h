#pragma once
#ifdef __linux__
#include <backend/linux/APIHook.h>
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
			APIHook* layer;
			Colormap colormap;
			XSetWindowAttributes setAttributes;
			XWindow window;
			XWindowAttributes attributes;

			X11Window(Display* display);
			virtual ~X11Window();

			void createXWindow(Visual* visual, float depth);

			void initSurface(app::API api);
			void apiInitalized();
			void setTitle(string title);
			void setVisible(bool visible);
			void setFullscreen(bool fullscreen);
			void close();
			void setCursorMode(input::CursorMode mode);
	};
}
#endif
