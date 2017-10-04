#pragma once
#include <input/InputSource.h>

namespace spruce {
	namespace input {
		class BasicInputSource : public InputSource<bool> {
			public:
				enum BasicInputSourceType {
					KEY, MOUSEBUTTON, AXIS, BUTTON
				};
				BasicInputSourceType type;
				uint8 joystick;
				uint16 code;
				float deadzone;

				BasicInputSource(BasicInputSourceType type, uint16 code);
				BasicInputSource(uint8 joystick, uint16 code);
				BasicInputSource(uint8 joystick, uint16 code, float deadzone);
				virtual ~BasicInputSource();

				void update();
				bool poll();
		};
	}
}
