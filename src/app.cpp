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
		Frame* encode;
		Frame* execute;

		void init() {
			os::init();
			task::init();
			api = nullptr;
			window = os::createWindow();
			debug = false;
			#ifdef DEBUG
			#ifdef TASK_PROFILE
			std::atexit([] {
				slog("saving task profile data to ", util::task::saveFile);
				util::task::saveProfileData(util::task::data, util::task::saveFile);
			});
			#endif
			#endif
			encode = new Frame();
			execute = new Frame();
		}

		void encodeRender(float delta) {
			screen->update(delta);
			screen->render(delta);
			waitForGraphicsTasks(true);
			#ifdef DEBUG
			#ifdef TASK_PROFILE
			util::task::dataMutex.lock();
			uint64 time = sys::timeNano();
			util::task::data.frameTimes.push_back(time);
			util::task::dataMutex.unlock();
			#endif
			#endif
		}

		void run() {
			uint64 lastTime = sys::timeNano();
			while (window->open) {
				os::updateStart();
				api->renderStart();
				graphics::delta = ((float)(sys::timeNano() - lastTime) / 1.0e9);
				lastTime = sys::timeNano();
				delete execute;
				execute = encode;
				encode = new Frame();
				if (screen != nullptr) {
					Task<void(float)> task = createTask(std::function<void(float)>(encodeRender), task::ENGINE, true, graphics::delta);
				}
				buffer<CommandBuffer*> commandBuffers = execute->getCommandBuffers();
				for (CommandBuffer* cmdBuffer : commandBuffers) {
					for (Command* command : cmdBuffer->commands) {
						command->execute();
					}
				}
				commandBuffers.free();
				waitForMainTasks();
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
			clearCommands();
		}

		void setScreen(graphics::Screen* newScreen) {
			screen = newScreen;
		}

		void clearCommands() {
			encode->mainCommandBuffer.reset();
			execute->mainCommandBuffer.reset();
		}
	}
}
