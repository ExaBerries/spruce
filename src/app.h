#pragma once
#include <common.h>
#include <API.h>
#include <backend/Window.h>
#include <graphics/Screen.h>
#include <Frame.h>

namespace spruce {
	class RenderAPI;

	namespace app {
		extern Window* window;
		extern API apiType;
		extern RenderAPI* api;
		extern graphics::Screen* screen;
		extern bool debug;
		extern Frame* encode;
		extern Frame* execute;

		void init();
		void run();
		void free();

		void setRenderAPI(API api);
		void setScreen(graphics::Screen* newScreen);
		void clearCommands();
	}
}
