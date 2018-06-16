#include <app.h>
#include <backend/api/opengl/OpenGL.h>
#include <backend/api/metal/Metal.h>
#include <backend/api/RenderAPI.h>
#include <backend/os.h>
#include <system/system.h>
#include <task/async.h>
#include <graphics/graphics.h>
#include <backend/task/taskmanager.h>
#ifdef DEBUG
#ifdef PROFILE
#include <util/profile/profile.h>
#include <util/profile/FrameProfileData.h>
#endif
#endif

namespace spruce {
	namespace app {
		Window* window;
		API apiType;
		RenderAPI* api;
		graphics::Screen* screen;
		bool debug;

		void init() {
			os::init();
			task::init();
			api = nullptr;
			window = os::createWindow();
			debug = false;
		}

		void run() {
			uint64 lastTime = sys::timeNano();
			#ifdef DEBUG
			#ifdef PROFILE
			util::profile::data.startTime = lastTime;
			#endif
			#endif
			while (window->open) {
				os::updateStart();
				api->renderStart();
				graphics::delta = ((float)(sys::timeNano() - lastTime) / 1.0e9);
				lastTime = sys::timeNano();
				if (screen != nullptr) {
					#ifdef DEBUG
					#ifdef PROFILE
					uint64 startTime = sys::timeNano();
					#endif
					#endif
					screen->update(graphics::delta);
					screen->render(graphics::delta);
					waitForGraphicsTasks();
					#ifdef DEBUG
					#ifdef PROFILE
					uint64 endTime = sys::timeNano();
					util::profile::dataMutex.lock();
					util::profile::FrameProfileData frameData;
					frameData.startTime = startTime;
					frameData.endTime = endTime;
					frameData.delta = graphics::delta;
					util::profile::data.frameProfiles.push_back(frameData);
					util::profile::dataMutex.unlock();
					#endif
					#endif
				}
				waitForMainTasks();
				std::vector<CommandBuffer*> commandBuffers = task::getCommandBuffers();
				for (CommandBuffer* cmdBuffer : commandBuffers) {
					for (Command* command : cmdBuffer->commands) {
						command->execute();
					}
					cmdBuffer->reset();
				}
				api->renderEnd();
				os::updateEnd();
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
			slog("saving task profile data to ", util::profile::saveFile);
			util::profile::dataMutex.lock();
			util::profile::saveProfileData(util::profile::data, util::profile::saveFile);
			util::profile::dataMutex.unlock();
			#endif
			#endif
		}

		void setRenderAPI(API api) {
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
				slog("unsupported API ", api);
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
		}

		void setScreen(graphics::Screen* newScreen) {
			screen = newScreen;
		}
	}
}
