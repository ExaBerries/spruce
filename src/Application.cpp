#include <Application.h>
#include <platform/Backend.h>
#include <platform/OpenGL/OpenGLBackend.h>

namespace spruce {
	namespace app {
		Backend* backend;
		graphics::Screen* screen;

		void init() {
			backend = new OpenGLBackend();
			backend->init();
		}

		void run() {
			backend->run();
		}

		void free() {
			delete screen;
			delete backend;
		}

		void setScreen(graphics::Screen* newScreen) {
			screen = newScreen;
		}
	}
}
