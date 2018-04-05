#include <app.h>
#include <backend/api/opengl/OpenGL.h>
#include <backend/api/metal/Metal.h>
#include <backend/api/RenderAPI.h>
#include <backend/os.h>
#include <system/system.h>
#include <backend/task/taskmanager.h>

namespace spruce {
	namespace app {
		Window* window;
		API apiType;
		RenderAPI* api;
		graphics::Screen* screen;
		bool debug;

		void init(API api) {
			apiType = api;
			os::init();
			task::init();
			if (!os::supportsAPI(api)) {
				serr("unsupported API");
				exit(EXIT_FAILURE);
			}
			window = os::createWindow(api);
			if (api == OPENGL) {
				app::api = new OpenGL(window);
			} else if (api == VULKAN) {
				slog("unsupported API");
				exit(EXIT_FAILURE);
			} else if (api == METAL) {
				app::api = new Metal(window);
			} else if (api == METAL2) {
				serr("unsupported API");
				exit(EXIT_FAILURE);
			} else if (api == DX11) {
				serr("unsupported API");
				exit(EXIT_FAILURE);
			} else if (api == DX12) {
				serr("unsupported API");
				exit(EXIT_FAILURE);
			}
			if (app::api == nullptr) {
				serr("could not instantiate api");
				exit(EXIT_FAILURE);
			}
			app::api->init();
			debug = false;
		}

		void run() {
			uint64 lastTime = sys::timeNano();
			while (window->open) {
				os::updateStart();
				api->updateStart();
				float delta = ((float)(sys::timeNano() - lastTime) / 1.0e9);
				lastTime = sys::timeNano();
				if (screen != nullptr) {
					screen->update(delta);
					screen->render(delta);
				}
				task::TaskBackend* taskBackend = task::getNextTask(true);
				while (taskBackend != nullptr) {
					if (taskBackend->functionData != nullptr) {
						taskBackend->functionData->execute();
						taskBackend->complete = true;
						delete taskBackend;
					} else {
						serr("invalid task, functionData == nullptr");
					}
				}
				api->updateEnd();
				os::updateEnd();
			}
		}

		void free() {
			if (window->open) {
				window->close();
			}
			delete window;
			delete screen;
			delete api;
			task::free();
			os::free();
		}

		void setScreen(graphics::Screen* newScreen) {
			screen = newScreen;
		}
	}
}
