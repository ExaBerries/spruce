#ifdef __linux__
#include <backend/os.h>
#include <system/system.h>
#include <input/input.h>
#include <app.h>
#include <backend/linux/X11Window.h>
#include <backend/api/opengl/OpenGL.h>
#include <backend/api/vulkan/Vulkan.h>
#include <backend/linux/opengl/X11OpenGLSurface.h>
#include <backend/linux/vulkan/X11VulkanSurface.h>
#include <X11/X.h>
#include <X11/Xlib.h>

namespace spruce {
	namespace os {
		buffer<uint16> keyCodes(nullptr);
		Display* display;

		void init() {
			keyCodes = buffer<uint16>(80);
			keyCodes[input::A] = 38;
			keyCodes[input::B] = 56;
			keyCodes[input::C] = 54;
			keyCodes[input::D] = 40;
			keyCodes[input::E] = 26;
			keyCodes[input::F] = 41;
			keyCodes[input::G] = 42;
			keyCodes[input::H] = 43;
			keyCodes[input::I] = 31;
			keyCodes[input::J] = 44;
			keyCodes[input::K] = 45;
			keyCodes[input::L] = 46;
			keyCodes[input::M] = 58;
			keyCodes[input::N] = 57;
			keyCodes[input::O] = 32;
			keyCodes[input::P] = 33;
			keyCodes[input::Q] = 24;
			keyCodes[input::R] = 27;
			keyCodes[input::S] = 39;
			keyCodes[input::T] = 28;
			keyCodes[input::U] = 30;
			keyCodes[input::V] = 55;
			keyCodes[input::W] = 25;
			keyCodes[input::X] = 53;
			keyCodes[input::Y] = 29;
			keyCodes[input::Z] = 52;
			keyCodes[input::ZERO] = 19;
			keyCodes[input::ONE] = 10;
			keyCodes[input::TWO] = 11;
			keyCodes[input::THREE] = 12;
			keyCodes[input::FOUR] = 13;
			keyCodes[input::FIVE] = 14;
			keyCodes[input::SIX] = 15;
			keyCodes[input::SEVEN] = 16;
			keyCodes[input::EIGHT] = 17;
			keyCodes[input::NINE] = 18;
			keyCodes[input::ENTER] = 36;
			keyCodes[input::ESCAPE] = 9;
			keyCodes[input::DELETE] = 51;
			keyCodes[input::HOME] = 0; // TODO get keycode
			keyCodes[input::INSERT] = 0; // TODO get keycode
			keyCodes[input::END] = 0; // TODO get keycode
			keyCodes[input::PAGE_UP] = 0; // TODO get keycode
			keyCodes[input::PAGE_DOWN] = 0; // TODO get keycode
			keyCodes[input::TAB] = 23;
			keyCodes[input::SPACE] = 64;
			keyCodes[input::SEMICOLON] = 47;
			keyCodes[input::APOSTROPHE] = 49;
			keyCodes[input::SLASH] = 61;
			keyCodes[input::BACKSLASH] = 51;
			keyCodes[input::PERIOD] = 60;
			keyCodes[input::COMMA] = 59;
			keyCodes[input::EQUAL] = 21;
			keyCodes[input::MINUS] = 20;
			keyCodes[input::LEFT_BRACKET] = 34;
			keyCodes[input::RIGHT_BRACKET] = 35;
			keyCodes[input::ARROW_LEFT] = 113;
			keyCodes[input::ARROW_RIGHT] = 114;
			keyCodes[input::ARROW_UP] = 111;
			keyCodes[input::ARROW_DOWN] = 116;
			keyCodes[input::SHIFT_LEFT] = 50;
			keyCodes[input::SHIFT_RIGHT] = 62;
			keyCodes[input::CONTROL_LEFT] = 37;
			keyCodes[input::CONTROL_RIGHT] = 0; // TODO get keycode
			keyCodes[input::ALT_LEFT] = 64;
			keyCodes[input::ALT_RIGHT] = 108;
			keyCodes[input::SUPER_LEFT] = 133;
			keyCodes[input::SUPER_RIGHT] = 134;
			keyCodes[input::F1] = 67;
			keyCodes[input::F2] = 68;
			keyCodes[input::F3] = 69;
			keyCodes[input::F4] = 70;
			keyCodes[input::F5] = 71;
			keyCodes[input::F6] = 72;
			keyCodes[input::F7] = 73;
			keyCodes[input::F8] = 74;
			keyCodes[input::F9] = 75;
			keyCodes[input::F10] = 76;
			keyCodes[input::F11] = 95;
			keyCodes[input::F12] = 96;
			display = XOpenDisplay(NULL);
			if (display == nullptr) {
				serr("x-server error could not get display");
				exit(EXIT_FAILURE);
			}
		}

		void free() {
			XOpenDisplay(NULL);
			XCloseDisplay(display);
		}

		Window* createWindow() {
			return new X11Window(display);
		}

		RenderAPI* initAPI(Window* window, app::API api) {
			X11Window* xwindow = (X11Window*) window;
			if (api == app::OPENGL) {
				xwindow->initOpenGL();
				X11RenderSurface* xsurface = (X11RenderSurface*) window->surface;
				OpenGL* gl = new OpenGL(window);
				gl->init();
				((X11OpenGLSurface*)xsurface)->apiInitalized(xwindow->window);
				return gl;
			} else if (api == app::VULKAN) {
				Vulkan* vulkan = new Vulkan(window);
				xwindow->initVulkan(&vulkan->context);
				X11RenderSurface* xsurface = (X11RenderSurface*) window->surface;
				((X11VulkanSurface*)xsurface)->addExtensions();
				vulkan->createContext();
				((X11VulkanSurface*)xsurface)->contextCreated(xwindow->window);
				vulkan->surfaceCreated();
				return vulkan;
			} else {
				return nullptr;
			}
		}

		bool supportsAPI(app::API api) {
			if (api == app::OPENGL) {
				return true;
			} else if (api == app::VULKAN) {
				return true;
			}
			return false;
		}

		bool supportsPrecompiledShader(app::API api) {
			if (api == app::OPENGL) {
				return true;
			} else if (api == app::VULKAN) {
				return true;
			}
			return false;
		}

		void updateStart() {
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
					input::MouseButton btn;
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
					newPos.x /= app::window->width;
					newPos.y /= app::window->height;
					newPos -= vec2f(0.5);
					for (uint16 i = 0; i < input::processors.size(); i++) {
						input::processors[i]->mouseMove(newPos);
					}
				} else  if (event.type == ConfigureNotify) {
					XConfigureEvent xcevent = event.xconfigure;
					app::window->width = xcevent.width;
					app::window->height = xcevent.height;
				} else if (event.type == ClientMessage) {
					if (event.xclient.data.l[0] == XInternAtom(display, "WM_DELETE_WINDOW", False)) {
						app::window->close();
					}
				}
			}
		}

		void updateEnd() {
		}

		uint16 codeFor(input::Key key) {
			return keyCodes[key];
		}

		string getHomePath() {
			return getenv("HOME");
		}

		string getBasePathInternal() {
			if (app::debug) {
				return "assets/";
			} else {
				return "";
			}
		}

		string getBasePathExternal() {
			return string();
		}

		bool isDir(string path) {
			return false;
		}

		bool exists(string path) {
			return false;
		}

		void createDir(string path) {
		}

		std::vector<string> listSubFiles(string path) {
			return std::vector<string>();
		}
	}

	namespace sys {
		string getCPUName() {
			return "";
		}

		uint16 getCPUCoreCount() {
			return 0;
		}

		uint64 getCPUFrequency() {
			return 0;
		}

		uint64 getCacheLineSize() {
			return 0;
		}

		uint64 getL1CacheSize() {
			return 0;
		}

		uint64 getL2CacheSize() {
			return 0;
		}

		uint64 getL3CacheSize() {
			return 0;
		}

		uint64 getRAMSize() {
			return 0;
		}

		uint64 getSwapUsed() {
			return 0;
		}
	}
}
#endif
