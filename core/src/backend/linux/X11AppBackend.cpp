#ifdef __linux__ 
#include <backend/linux/X11AppBackend.h>
#include <backend/linux/X11Window.h>

namespace spruce {
	X11AppBackend::X11AppBackend() {
		display = XOpenDisplay(NULL);
		if (display == nullptr) {
			serr("x-server error could not get display");
			exit(EXIT_FAILURE);
		}
	}

	X11AppBackend::~X11AppBackend() {
		XOpenDisplay(NULL);
		XCloseDisplay(display);
	}

	Window* X11AppBackend::createWindow() {
		return new X11Window(display);
	}

	void X11AppBackend::update() {
		XEvent event;
		while (XPending(display)) {
			XNextEvent(display, &event);
			if (event.type == KeyPress) {
				XKeyEvent kevent = event.xkey;
				for (uint16 i = 0; i < input::processors.size(); i++) {
					input::processors[i]->keyDown(kevent.keycode);
				}
			} else if (event.type == KeyRelease) {
				XKeyEvent kevent = event.xkey;
				for (uint16 i = 0; i < input::processors.size(); i++) {
					input::processors[i]->keyUp(kevent.keycode);
				}
			} else if (event.type == ButtonPress) {
				XButtonEvent bevent = event.xbutton;
				input::MouseButton btn = input::LEFT;
				if (bevent.button == 1) {
					btn = input::LEFT;
				} else if (bevent.button == 2) {
					btn = input::CENTER;
				} else if (bevent.button == 3) {
					btn = input::RIGHT;
				}
				for (uint16 i = 0; i < input::processors.size(); i++) {
					input::processors[i]->mouseDown(btn);
				}
			} else if (event.type == ButtonRelease) {
				XButtonEvent bevent = event.xbutton;
				input::MouseButton btn;
				if (bevent.button == 1) {
					btn = input::LEFT;
				} else if (bevent.button == 2) {
					btn = input::CENTER;
				} else if (bevent.button == 3) {
					btn = input::RIGHT;
				}
				for (uint16 i = 0; i < input::processors.size(); i++) {
					input::processors[i]->mouseUp(btn);
				}
			} else if (event.type == MotionNotify) {
				XButtonEvent bevent = event.xbutton;
				vec2f newPos = vec2f(bevent.x, bevent.y);
				//newPos.x /= app::window->width;
				//newPos.y /= app::window->height;
				newPos -= vec2f(0.5);
				for (uint16 i = 0; i < input::processors.size(); i++) {
					input::processors[i]->mouseMove(newPos);
				}
			} else  if (event.type == ConfigureNotify) {
				XConfigureEvent xcevent = event.xconfigure;
				//app::window->width = xcevent.width;
				//app::window->height = xcevent.height;
			} else if (event.type == ClientMessage) {
				if ((uint32)event.xclient.data.l[0] == XInternAtom(display, "WM_DELETE_WINDOW", False)) {
					//app::window->close();
				}
			}
		}
	}
}
#endif