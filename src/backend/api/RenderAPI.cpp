#include <backend/api/RenderAPI.h>
#include <common.h>

namespace spruce {
	RenderAPI::RenderAPI(Window* window, vec3f ndcSize) {
		this->window = window;
		this->ndcSize = ndcSize;
	}

	RenderAPI::~RenderAPI() {
	}
}
