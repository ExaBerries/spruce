#pragma once
#include <GLFW/glfw3.h>
#include "graphics/Screen.h"
#include "log.h"

namespace spruce {
	class Game {
		private:
			GLFWwindow* window;
			graphics::Screen* screen;
		public:
			Game();
			virtual ~Game();

			void init();
			void run();
			void setScreen(graphics::Screen* screen);
	};
}
