#pragma once
#include <common.h>
#include <input/Key.h>
#include <input/MouseButton.h>

namespace spruce {
	namespace input {
		class InputProcessor {
			public:
				InputProcessor();
				virtual ~InputProcessor();

				virtual void keyUp(uint16 code) = 0;
				virtual void keyDown(uint16 code) = 0;
				virtual void mouseUp(MouseButton button) = 0;
				virtual void mouseDown(MouseButton button) = 0;
				virtual void mouseMove(vec2f newPos) = 0;
		};
	}
}
