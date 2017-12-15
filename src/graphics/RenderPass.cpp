#include <graphics/RenderPass.h>

namespace spruce {
	namespace graphics {
		RenderPass::RenderPass() {
			target = nullptr;
		}

		RenderPass::~RenderPass() {
			if (target != nullptr) {
				delete target;
			}
		}
	}
}
