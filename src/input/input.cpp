#include <Application.h>
#include <input/input.h>
#include <platform/Backend.h>

namespace spruce {
	namespace input {
		bool keyPressed(Key key) {
			return app::backend->keyPressed(codeFor(key));
		}

		bool mousePressed(MouseButton button) {
			return app::backend->mouseButtonPressed(codeFor(button));
		}

		uint16 codeFor(Key key) {
			return app::backend->codeFor(key);
		}

		uint16 codeFor(MouseButton button) {
			return app::backend->codeFor(button);
		}
	}
}
