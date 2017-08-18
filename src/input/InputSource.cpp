#include <app.h>
#include <input/InputSource.h>
#include <backend/Backend.h>

namespace spruce {
	namespace input {
		InputSource::InputSource(string name, InputSourceType type, uint16 code) {
			this->name = name;
			this->type = type;
			this->code = code;
			joystick = 0;
			deadzone = 0.1;

		}

		InputSource::InputSource(string name, InputSourceType type, uint16 joystick, uint16 code, float deadzone) {
			this->name = name;
			this->type = type;
			this->code = code;
			this->joystick = joystick;
			this->deadzone = deadzone;
		}

		InputSource::~InputSource() {
		}

		bool InputSource::active() {
			if (type == KEYBOARD) {
				return app::backend->keyPressed(code);
			} else if (type == MOUSE) {
				return app::backend->mouseButtonPressed(code);
			} else if (type == AXIS) {
				return true;
			} else if (type == BUTTON) {
				return true;
			}
			return false;
		}
	}
}
