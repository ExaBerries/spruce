#pragma once
#include <common.h>

namespace spruce {
	namespace input {
		class InputSource {
			public:
				enum InputSourceType {
					KEYBOARD, MOUSE, AXIS, BUTTON
				};
				string name;
				InputSourceType type;
				uint16 joystick;
				uint16 code;
				float deadzone;

				InputSource(string name, InputSourceType type, uint16 code);
				InputSource(string name, InputSourceType type, uint16 joystick, uint16 code, float deadzone);
				virtual ~InputSource();

				bool active();
		};
	}
}
