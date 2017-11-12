#include <app.h>
#include <backend/api/RenderAPI.h>
#include <input/input.h>
#include <backend/Window.h>
#include <app.h>
#include <backend/os.h>

namespace spruce {
	namespace input {
		std::vector<InputProcessor*> processors;

		void addProcessor(InputProcessor* processor) {
			processors.push_back(processor);
		}

		void removeProcessor(InputProcessor* processor) {
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
