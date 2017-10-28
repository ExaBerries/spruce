#pragma once
#include <backend/Window.h>

namespace spruce {
	void makeContextCurrent(Window* window);
	void swapBuffers(Window* window);
	void swapInterval(Window* window, uint8 interval);
}
