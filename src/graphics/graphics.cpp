#include "graphics.h"
#include "../Application.h"
#include "../platform/Backend.h"

namespace spruce {
	namespace graphics {
		Mesh* createMesh(int vertexCount, float* vertices, int indexCount, unsigned short* indices, Shader& shader) {
			return app::backend->createMesh(vertexCount, vertices, indexCount, indices, shader);
		}

		Shader* createShader(char* vertSource, char* fragSource, int attributesCount, VertexAttribute* attributes) {
			return app::backend->createShader(vertSource, fragSource, attributesCount, attributes);
		}

		MeshRenderer* createMeshRenderer() {
			return app::backend->createMeshRenderer();
		}

		int getWidth() {
			return app::backend->getWindowWidth();
		}

		int getHeight() {
			return app::backend->getWindowHeight();
		}
	}
}
