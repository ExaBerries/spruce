#include <graphics/graphics.h>
#include <Application.h>
#include <platform/Backend.h>
#include <graphics/PerspectiveCamera.h>

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

		Camera* createCamera(uint16 viewportWidth, uint16 viewportHeight, float fieldOfView, float near, float far, vec3f& up) {
			return new PerspectiveCamera(viewportWidth, viewportHeight, fieldOfView, near, far, up);
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
