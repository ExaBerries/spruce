#pragma once
#include <common.h>
#include <API.h>
#include <backend/Window.h>
#include <graphics/Screen.h>

namespace spruce {
	class RenderAPI;

	namespace app {
		extern Window* window;
		extern RenderAPI* api;
		extern graphics::Screen* screen;

		void init(API api);
		void run();
		void free();

		void setScreen(graphics::Screen* newScreen);
	}
}
