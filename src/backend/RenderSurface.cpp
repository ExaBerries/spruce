#include <backend/RenderSurface.h>

namespace spruce {
	RenderSurface::RenderSurface() {
		target = nullptr;
	}

	RenderSurface::~RenderSurface() {
		if (target != nullptr) {
			delete target;
		}
	}
}
