#pragma once
#include <common.h>
#include <input/Key.h>
#include <input/MouseButton.h>

namespace spruce {
	namespace input {
		class InputProcessor {
			public:
				InputProcessor() = default;
				InputProcessor(const InputProcessor&) = default;
				InputProcessor(InputProcessor&&) noexcept = default;
				virtual ~InputProcessor() = default;

				virtual void keyUp(uint16 code) noexcept = 0;
				virtual void keyDown(uint16 code) noexcept = 0;
				virtual void mouseUp(MouseButton button) noexcept = 0;
				virtual void mouseDown(MouseButton button) noexcept = 0;
				virtual void mouseMove(vec2f newPos) noexcept = 0;

				InputProcessor& operator=(const InputProcessor&) = default;
				InputProcessor& operator=(InputProcessor&&) noexcept = default;
		};
	}
}
