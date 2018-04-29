#include <app.h>
#include <backend/api/opengl/OpenGL.h>
#include <backend/api/metal/Metal.h>
#include <backend/api/RenderAPI.h>
#include <backend/os.h>
#include <system/system.h>
#include <task/async.h>
#ifdef DEBUG
#ifdef TASK_PROFILE
#include <util/task/taskprofile.h>
#endif
#endif

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
			#ifdef DEBUG
			#ifdef TASK_PROFILE
			std::atexit([] {
				slog("saving task profile data to ", util::task::saveFile);
				util::task::saveProfileData(util::task::data, util::task::saveFile);
			});
			#endif
			#endif
		}

		void run() {
			uint64 lastTime = sys::timeNano();
			while (window->open) {
				os::updateStart();
				api->renderStart();
				float delta = ((float)(sys::timeNano() - lastTime) / 1.0e9);
				lastTime = sys::timeNano();
				if (screen != nullptr) {
					screen->update(delta);
					screen->render(delta);
					waitForGraphicsTasks();
					#ifdef DEBUG
					#ifdef TASK_PROFILE
					util::task::dataMutex.lock();
					util::task::data.frameTimes.push_back(sys::timeNano());
					util::task::dataMutex.unlock();
					#endif
					#endif
				}
				waitForMainTasks();
				api->renderEnd();
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
