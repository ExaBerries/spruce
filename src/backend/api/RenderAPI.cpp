#include <backend/api/RenderAPI.h>
#include <common.h>

namespace spruce {
	RenderAPI::RenderAPI(Window* window) {
		this->window = window;
	}

	RenderAPI::~RenderAPI() {
		delete window;
	}
}
