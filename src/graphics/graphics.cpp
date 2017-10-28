#include <app.h>
#include <backend/api/RenderAPI.h>
#include <graphics/graphics.h>
#include <graphics/PerspectiveCamera.h>
#include <graphics/OrthographicCamera.h>
#include <thread>

namespace spruce {
	namespace graphics {
		Mesh* createMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices) {
			return app::api->createMesh(vertexCount, vertices, indexCount, indices);
		}

		Shader* createShader(string& vertSource, string& fragSource, uint16 attributesCount, VertexAttribute* attributes) {
			return app::api->createShader(vertSource, fragSource, attributesCount, attributes);
		}

		MeshRenderer* createMeshRenderer() {
			return app::api->createMeshRenderer();
		}

		ShapeRenderer* createShapeRenderer() {
			return app::api->createShapeRenderer();
		}

		PerspectiveCamera* createPerspectiveCamera(float viewportWidth, float viewportHeight, float fieldOfView, float near, float far, vec3f& up, vec3f& dir) {
			return new PerspectiveCamera(viewportWidth, viewportHeight, fieldOfView, near, far, up, dir);
		}

		OrthographicCamera* createOrthographicCamera(float viewportWidth, float viewportHeight, float near, float far, vec3f& up) {
			return new OrthographicCamera(viewportWidth, viewportHeight, near, far, up);
		}

		Texture* createTexture(string& path) {
			return app::api->createTexture(path);
		}

		void setBlend(bool value) {
			app::api->setBlend(value);
		}

		void setDepth(bool value) {
			app::api->setDepth(value);
		}

		int getWidth() {
			return app::window->width;
		}

		int getHeight() {
			return app::window->height;
		}

		uint16 getCPUNumThreads() {
			return std::thread::hardware_concurrency();
		}

		string getGPUVendor() {
			return app::api->getGPUVendor();
		}

		uint16 getAPIVersionMajor() {
			return app::api->getAPIVersionMajor();
		}

		uint16 getAPIVersionMinor() {
			return app::api->getAPIVersionMinor();
		}

		string getAPIRendererName() {
			return app::api->getAPIRendererName();
		}
	}
}
