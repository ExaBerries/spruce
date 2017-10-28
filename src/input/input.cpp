#include <app.h>
#include <backend/api/RenderAPI.h>
#include <input/input.h>

namespace spruce {
	namespace input {
		void setCursorMode(CursorMode mode) {
			//return app::api->setCursorMode(mode);
		}

		bool keyPressed(Key key) {
			return false;//return app::api->keyPressed(codeFor(key));
		}

		bool mousePressed(MouseButton button) {
			return false;//return app::api->mouseButtonPressed(codeFor(button));
		}

		vec2f mousePos() {
			return vec2f();//return app::api->mousePos();
		}

		uint16 codeFor(Key key) {
			return 0;//return app::api->codeFor(key);
		}

		uint16 codeFor(MouseButton button) {
			return 0;//return app::api->codeFor(button);
		}
	}
}
