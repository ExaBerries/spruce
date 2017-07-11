#pragma once
#include "graphics/Screen.h"
#include "log.h"

namespace spruce {
	class Backend;

	namespace app {
		extern Backend* backend;
		extern graphics::Screen* screen;

		void init();
		void run();
		void free();

		void setScreen(graphics::Screen* newScreen);
	}
}
