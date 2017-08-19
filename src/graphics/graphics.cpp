#include <app.h>
#include <graphics/graphics.h>
#include <backend/Backend.h>
#include <graphics/PerspectiveCamera.h>
#include <graphics/OrthographicCamera.h>
#include <thread>

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

		Camera* createPerspectiveCamera(float viewportWidth, float viewportHeight, float fieldOfView, float near, float far, vec3f& up) {
			return new PerspectiveCamera(viewportWidth, viewportHeight, fieldOfView, near, far, up);
		}

		Camera* createOrthographicCamera(float viewportWidth, float viewportHeight, float near, float far, vec3f& up) {
			return new OrthographicCamera(viewportWidth, viewportHeight, near, far, up);
		}

		Texture* createTexture(string& path) {
			return app::backend->createTexture(path);
		}

		int getWidth() {
			return app::backend->windowWidth;
		}

		int getHeight() {
			return app::backend->windowHeight;
		}

		uint16 getCPUNumThreads() {
			return std::thread::hardware_concurrency();
		}

		string getGPUVendor() {
			return app::backend->getGPUVendor();
		}

		uint16 getAPIVersionMajor() {
			return app::backend->getAPIVersionMajor();
		}

		uint16 getAPIVersionMinor() {
			return app::backend->getAPIVersionMinor();
		}

		string getAPIRendererName() {
			return app::backend->getAPIRendererName();
		}
	}
}
