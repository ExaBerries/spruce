#pragma once
#include <common.h>
#include <input/MouseButton.h>
#include <input/CursorMode.h>
#include <input/Key.h>
#include <input/InputProcessor.h>

namespace spruce {
	namespace input {
		extern std::vector<InputProcessor*> processors;

		void addProcessor(InputProcessor* processor) noexcept;
		void removeProcessor(InputProcessor* processor) noexcept;

		void setCursorMode(CursorMode mode) noexcept;

		[[nodiscard]] uint16 codeFor(Key key) noexcept;
	}
}
