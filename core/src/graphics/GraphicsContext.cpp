#include <graphics/GraphicsContext.h>
#include <graphics/command/render/RenderMeshCommand.h>

namespace spruce {
	namespace graphics {
		GraphicsContext::GraphicsContext() {
		}

		GraphicsContext::~GraphicsContext() {
		}

		void GraphicsContext::render(Mesh* mesh, Shader* shader, Primitive primitive) {
			cmdBuffer.add(new cmd::RenderMeshCommand(mesh, shader, primitive));
		}
	}
}
