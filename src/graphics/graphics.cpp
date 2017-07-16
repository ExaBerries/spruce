#include <graphics/graphics.h>
#include <Application.h>
#include <platform/Backend.h>

namespace spruce {
	namespace graphics {
		Mesh* createMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices) {
			return app::backend->createMesh(vertexCount, vertices, indexCount, indices);
		}

		Shader* createShader(string& vertSource, string& fragSource, uint16 attributesCount, VertexAttribute* attributes) {
			return app::backend->createShader(vertSource, fragSource, attributesCount, attributes);
		}

		MeshRenderer* createMeshRenderer() {
			return app::backend->createMeshRenderer();
		}

		Texture* createTexture(string& path) {
			return app::backend->createTexture(path);
		}

		int getWidth() {
			return app::backend->getWindowWidth();
		}

		int getHeight() {
			return app::backend->getWindowHeight();
		}
	}
}
