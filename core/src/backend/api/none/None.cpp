#include <backend/api/none/None.h>

namespace spruce {
	None::None(Window* window) : RenderAPI(window, vec3f(2, 2, 2)) {
	}

	None::~None() {
	}
}
