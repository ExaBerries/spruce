#include <platform/Backend.h>
#include <common.h>

namespace spruce {
	Backend::~Backend() {
	}

	uint16 Backend::getWindowWidth() {
		return windowWidth;
	}

	uint16 Backend::getWindowHeight() {
		return windowHeight;
	}
}
