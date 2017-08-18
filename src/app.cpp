#include <app.h>
#include <backend/Backend.h>
#include <backend/opengl/OpenGLBackend.h>
#include <thread>
#include <system/system.h>

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
