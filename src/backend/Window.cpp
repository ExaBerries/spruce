#include <backend/Window.h>

namespace spruce {
	Window::Window() {
		width = 0;
		height = 0;
		visible = false;
		open = true;
		cursorMode = input::CursorMode::NORMAL;
	}

	Window::~Window() {
	}

}
