#include <app.h>
#include <backend/api/RenderAPI.h>
#include <backend/api/opengl/OpenGL.h>
#include <backend/api/metal/Metal.h>
#include <backend/os.h>
#include <system/system.h>
#include <task/async.h>
#include <graphics/graphics.h>
#ifdef DEBUG
#ifdef PROFILE
#include <util/profile/profile.h>
#endif
#endif

namespace spruce {
	namespace app {
		Window* window;
		API apiType;
		RenderAPI* api;
		graphics::Screen* screen;
		bool debug;
		Pipeline* pipeline;

		void init() {
			os::init();
			task::init();
			api = nullptr;
			window = os::createWindow();
			screen = nullptr;
			debug = false;
			pipeline = nullptr;
			graphics::width = graphics::getWindowWidth();
			graphics::height = graphics::getWindowHeight();
			graphics::vsync = true;
		}

		void run() {
			uint64 lastTime = sys::timeNano();
			#ifdef DEBUG
			#ifdef PROFILE
			util::profile::data.startTime = lastTime;
			#endif
			#endif
			while (window->open) {
				graphics::delta = ((float)(sys::timeNano() - lastTime) / 1.0e9);
				lastTime = sys::timeNano();
				pipeline->execute();
				mem::update();
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
			#ifdef DEBUG
			#ifdef PROFILE
			slog("saving profile data to ", util::profile::saveFile);
			util::profile::dataMutex.lock();
			util::profile::saveProfileData(util::profile::data, util::profile::saveFile);
			util::profile::dataMutex.unlock();
			#endif
			#endif
		}

		void setPipeline(Pipeline* pipeline) {
			if (app::pipeline != nullptr) {
				delete app::pipeline;
			}
			app::pipeline = pipeline;
		}

		void setRenderAPI(API api) {
			waitForMainTasks();
			if (app::api != nullptr) {
				delete app::api;
			}
			if (!os::supportsAPI(api)) {
				serr("unsupported API");
				exit(EXIT_FAILURE);
			}
			apiType = api;
			window->initForAPI(api);
			if (api == OPENGL) {
				app::api = new OpenGL(window);
			} else if (api == VULKAN) {
				serr("unsupported API ", api);
				exit(EXIT_FAILURE);
			} else if (api == METAL) {
				app::api = new Metal(window);
			} else if (api == METAL2) {
				serr("unsupported API ", api);
				exit(EXIT_FAILURE);
			} else if (api == DX11) {
				serr("unsupported API ", api);
				exit(EXIT_FAILURE);
			} else if (api == DX12) {
				serr("unsupported API ", api);
				exit(EXIT_FAILURE);
			}
			if (app::api == nullptr) {
				serr("could not instantiate api ", api);
				exit(EXIT_FAILURE);
			}
			app::api->init();
			clearCommands();
		}

		void setScreen(graphics::Screen* newScreen) {
			if (screen != nullptr) {
				delete screen;
			}
			screen = newScreen;
			clearCommands();
		}

		void clearCommands() {
			pipeline->clearCommands();
		}
	}
}
