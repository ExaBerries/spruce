#include <graphics/graphics.h>
#include <backend/api/RenderAPI.h>
#include <backend/os.h>
#include <graphics/PerspectiveCamera.h>
#include <graphics/OrthographicCamera.h>
#include <io/file.h>
#include <app.h>
#include <thread>

namespace spruce {
	namespace graphics {
		Mesh* createMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices) {
			return app::api->createMesh(vertexCount, vertices, indexCount, indices);
		}

		Shader* createShader(string path, uint16 attributeCount, VertexAttribute* attributes) {
			uint32 count = 0;
			uint8* data = io::readFileBin(path, count);
			if (data == nullptr) {
				log("could not read shader file: ", path);
				return nullptr;
			}
			if (data[0] == 1) {
				uint32 i = sizeof(uint8);
				uint32 glVertSourceSize = 0;
				memcpy(&glVertSourceSize, data + i, sizeof(uint32));
				i += sizeof(uint32);
				uint32 glFragSourceSize = 0;
				memcpy(&glFragSourceSize, data + i, sizeof(uint32));
				i += sizeof(uint32);
				uint32 glVertSize = 0;
				memcpy(&glVertSize, data + i, sizeof(uint32));
				i += sizeof(uint32);
				uint32 glFragSize = 0;
				memcpy(&glFragSize, data + i, sizeof(uint32));
				i += sizeof(uint32);
				if (app::apiType == app::OPENGL) {
					string vertSource = string((const char*) data + i);
					string fragSource = string((const char*) data + i + glVertSourceSize);
					i += glVertSourceSize + glFragSourceSize;
					uint8* vertexData = new uint8[glVertSize / sizeof(uint8)];
					memcpy(vertexData, data + i, glVertSize);
					uint8* fragmentData = new uint8[glFragSize / sizeof(uint8)];
					memcpy(fragmentData, data + i + glVertSize, glFragSize);
					delete[] data;
					if (os::supportsPrecompiledShader(app::OPENGL)) {
						return app::api->createShader(vertexData, glVertSize, fragmentData, glFragSize, attributeCount, attributes);
					} else {
						return app::api->createShader(vertSource, fragSource, attributeCount, attributes);
					}
				}
				i += glVertSize + glFragSize;
				uint32 metalSize = 0;
				memcpy(&metalSize, data + i, sizeof(uint32));
				i += sizeof(uint32);
				if (app::apiType == app::METAL) {
					if (metalSize == 0) {
						log("no metal shader data");
						return nullptr;
					}
					uint8* metalData = new uint8[metalSize / sizeof(uint8)];
					memcpy(metalData, data + i, metalSize);
					delete[] data;
					return app::api->createShader(metalData, metalSize, nullptr, 0, attributeCount, attributes);
				}
				i += metalSize;
				if (app::apiType == app::VULKAN) {
					delete[] data;
					return nullptr; // TODO create Vulkan shader from SPIR-V data
				}
				if (app::apiType == app::DX11) {
					delete[] data;
					return nullptr; // TODO support dx11 HLSL
				}
				if (app::apiType == app::DX12) {
					delete[] data;
					return nullptr; // TODO support dx12 HLSL
				}
			} else {
				log("invalid version of spruce-shader");
			}
			delete[] data;
			return nullptr;
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
