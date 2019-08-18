#ifdef __linux__
#include <backend/linux/X11AppBackend.h>

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

	owner<Window> X11AppBackend::createWindow() {
		X11Window* window = new X11Window(display);
		x11Windows.push_back(window);
		return window;
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
				for (X11Window*& window : x11Windows) {
					if (window->window == bevent.window) {
						newPos.x /= window->width;
						newPos.y /= window->height;
						newPos -= vec2f(0.5);
						for (uint16 i = 0; i < input::processors.size(); i++) {
							input::processors[i]->mouseMove(newPos);
						}
						break;
					}
				}
			} else  if (event.type == ConfigureNotify) {
				XConfigureEvent xcevent = event.xconfigure;
				for (X11Window*& window : x11Windows) {
					if (window->window == xcevent.window) {
						window->width = xcevent.width;
						window->height = xcevent.height;
					}
				}
			} else if (event.type == ClientMessage) {
				XClientMessageEvent cmevent = event.xclient;
				if ((uint32)event.xclient.data.l[0] == XInternAtom(display, "WM_DELETE_WINDOW", False)) {
					for (X11Window*& window : x11Windows) {
						if (window->window == cmevent.window) {
							window->close();
						}
					}
				}
			}
		}
	}
}
#endif
