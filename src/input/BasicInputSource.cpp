#include <input/BasicInputSource.h>
#include <app.h>
#include <backend/Backend.h>

namespace spruce {
	namespace input {
		template <>
		InputSource<bool>::InputSource() {
		}

		template <>
		InputSource<bool>::~InputSource() {
		}

		template <>
		void InputSource<bool>::update() {
		}

		template <>
		bool InputSource<bool>::poll() {
			return false;
		}

		BasicInputSource::BasicInputSource(BasicInputSourceType type, uint16 code) {
			this->type = type;
			this->code = code;
			joystick = 0;
			deadzone = 0;
		}

		BasicInputSource::BasicInputSource(uint8 joystick, uint16 code) {
			this->type = BUTTON;
			this->joystick = joystick;
			this->code = code;
			deadzone = 0;
		}

		BasicInputSource::BasicInputSource(uint8 joystick, uint16 code, float deadzone) {
			this->type = AXIS;
			this->joystick = joystick;
			this->code = code;
			this->deadzone = deadzone;
		}

		BasicInputSource::~BasicInputSource() {
		}


		void BasicInputSource::update() {
		}

		bool BasicInputSource::poll() {
			if (type == KEY) {
				return app::backend->keyPressed(code);
			} else if (type == MOUSEBUTTON) {
				return app::backend->mouseButtonPressed(code);
			} else if (type == AXIS) {
				return false;//app::backend->axis(joystick, code) > deadzone;
			} else if (type == BUTTON) {
				return false;//app::backend->button(joystick, code);
			}
			return false;
		}
	}
}
