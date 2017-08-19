#include <app.h>
#include <backend/Backend.h>
#include <input/input.h>

namespace spruce {
	namespace input {
		void setCursorMode(CursorMode mode) {
			return app::backend->setCursorMode(mode);
		}

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
