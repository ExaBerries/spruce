#include <input/input.h>
#include <app.h>
#include <backend/api/RenderAPI.h>
#include <backend/Window.h>
#include <backend/os.h>
#include <task/async.h>

namespace spruce {
	namespace input {
		std::vector<InputProcessor*> processors;
		std::mutex processorsMutex;

		void addProcessor(InputProcessor* processor) {
			std::lock_guard<std::mutex> processorsLock(processorsMutex);
			processors.push_back(processor);
		}

		void removeProcessor(InputProcessor* processor) {
			std::lock_guard<std::mutex> processorsLock(processorsMutex);
			for (uint16 i = 0; i < processors.size(); i++) {
				if (processors[i] == processor) {
					processors.erase(processors.begin() + i);
				}
			}
		}

		void setCursorMode(CursorMode mode) {
			app::window->setCursorMode(mode);
		}

		uint16 codeFor(Key key) {
			return os::codeFor(key);
		}
	}
}
