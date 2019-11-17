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

	[[nodiscard]] owner<Window> X11AppBackend::createWindow() noexcept {
		X11Window* window = new X11Window(display);
		x11Windows.push_back(window);
		return window;
	}

	void X11AppBackend::update() noexcept {
		XEvent event;
		while (XPending(display)) {
			XNextEvent(display, &event);
			if (event.type == KeyPress) {
				XKeyEvent kevent = event.xkey;
				for (input::InputProcessor* processor : input::processors) {
					processor->keyDown(static_cast<uint16>(kevent.keycode));
				}
			} else if (event.type == KeyRelease) {
				XKeyEvent kevent = event.xkey;
				for (input::InputProcessor* processor : input::processors) {
					processor->keyUp(static_cast<uint16>(kevent.keycode));
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
				for (input::InputProcessor* processor : input::processors) {
					processor->mouseDown(btn);
				}
			} else if (event.type == ButtonRelease) {
				XButtonEvent bevent = event.xbutton;
				input::MouseButton btn = input::LEFT;
				if (bevent.button == 1) {
					btn = input::LEFT;
				} else if (bevent.button == 2) {
					btn = input::CENTER;
				} else if (bevent.button == 3) {
					btn = input::RIGHT;
				}
				for (input::InputProcessor* processor : input::processors) {
					processor->mouseUp(btn);
				}
			} else if (event.type == MotionNotify) {
				XButtonEvent bevent = event.xbutton;
				vec2f newPos = vec2f(static_cast<float>(bevent.x), static_cast<float>(bevent.y));
				for (X11Window*& window : x11Windows) {
					if (window->window == bevent.window) {
						newPos.x /= static_cast<float>(window->width);
						newPos.y /= static_cast<float>(window->height);
						newPos -= vec2f(0.5);
						for (input::InputProcessor* processor : input::processors) {
							processor->mouseMove(newPos);
						}
						break;
					}
				}
			} else  if (event.type == ConfigureNotify) {
				XConfigureEvent xcevent = event.xconfigure;
				for (X11Window*& window : x11Windows) {
					if (window->window == xcevent.window) {
						window->width = static_cast<uint32>(xcevent.width);
						window->height = static_cast<uint32>(xcevent.height);
					}
				}
			} else if (event.type == ClientMessage) {
				XClientMessageEvent cmevent = event.xclient;
				if (static_cast<uint32>(event.xclient.data.l[0]) == XInternAtom(display, "WM_DELETE_WINDOW", False)) {
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
