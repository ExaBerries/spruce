#include <app.h>
#include <backend/api/opengl/OpenGL.h>
#include <backend/api/RenderAPI.h>
#include <backend/os.h>
#include <system/system.h>
#include <thread>

namespace spruce {
	namespace app {
		Window* window;
		RenderAPI* api;
		graphics::Screen* screen;

		void init(API api) {
			os::init();
			if (!os::supportsAPI(api)) {
				log("unsupported API");
				exit(EXIT_FAILURE);
			}
			window = os::createWindow(api);
			if (api == OPENGL) {
				app::api = new OpenGL(window);
			} else if (api == VULKAN) {
				log("unsupported API");
				exit(EXIT_FAILURE);
			} else if (api == METAL) {
				log("unsupported API");
				exit(EXIT_FAILURE);
			} else if (api == METAL2) {
				log("unsupported API");
				exit(EXIT_FAILURE);
			} else if (api == DX11) {
				log("unsupported API");
				exit(EXIT_FAILURE);
			} else if (api == DX12) {
				log("unsupported API");
				exit(EXIT_FAILURE);
			}
			app::api->init();
		}

		void run() {
			float lastTime = os::timeSec();
			while (true) {
				os::updateStart();
				api->updateStart();
				float delta = os::timeSec() - lastTime;
				if (screen != nullptr) {
					screen->update(delta);
					screen->render(delta);
				}
				lastTime = os::timeSec();
				api->updateEnd();
				os::updateEnd();
			}
		}

		void free() {
			window->close();
			delete window;
			delete screen;
			delete api;
		}

		void setScreen(graphics::Screen* newScreen) {
			screen = newScreen;
		}
	}
}
