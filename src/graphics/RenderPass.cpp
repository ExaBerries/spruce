#include <graphics/RenderPass.h>
#include <app/app.h>

namespace spruce {
	namespace graphics {
		RenderPass::RenderPass() {
			target = app::window->surface->target;
		}

		RenderPass::~RenderPass() {
			if (target != nullptr && target != app::window->surface->target) {
				delete target;
			}
		}
	}
}
