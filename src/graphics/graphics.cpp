#include <graphics/graphics.h>
#include <backend/api/RenderAPI.h>
#include <backend/os.h>
#include <io/file.h>
#include <app.h>
#include <task/async.h>
#include <backend/task/taskmanager.h>
#include <graphics/command/render/RenderBufferCommand.h>
#include <graphics/command/render/RenderFontCommand.h>
#include <graphics/command/render/RenderLineCommand.h>
#include <graphics/command/render/RenderMeshCommand.h>
#include <graphics/command/render/RenderPassCommand.h>
#include <graphics/command/render/RenderRectCommand.h>

namespace spruce {
	namespace graphics {
		float delta;
		uint16 width;
		uint16 height;
		bool vsync;

		CommandBuffer& getCommandBuffer() {
			return app::pipeline->getCommandBuffer();
		}

		Mesh* createMesh(buffer<float> vertices, buffer<uint16> indices) {
			return app::api->createMesh(vertices, indices);
		}

		Shader* createShader(const FileHandle& file, buffer<VertexAttribute> attributes) {
			buffer<uint8> data = io::readFileBin(file);
			if (data == nullptr) {
				serr("could not read shader file: ", file);
				return nullptr;
			}
			if (data[0] == 2) {
				uint64 i = sizeof(uint8);
				uint64 glVertSourceSize = 0;
				memcpy(&glVertSourceSize, data + i, sizeof(uint64));
				i += sizeof(uint64);
				uint64 glFragSourceSize = 0;
				memcpy(&glFragSourceSize, data + i, sizeof(uint64));
				i += sizeof(uint64);
				uint64 glVertSize = 0;
				memcpy(&glVertSize, data + i, sizeof(uint64));
				i += sizeof(uint64);
				uint64 glFragSize = 0;
				memcpy(&glFragSize, data + i, sizeof(uint64));
				i += sizeof(uint64);
				if (app::apiType == app::OPENGL) {
					string vertSource = string((char*) data + i);
					string fragSource = string((char*) data + i + glVertSourceSize);
					i += glVertSourceSize + glFragSourceSize;
					buffer<uint8> vertexData(glVertSize / sizeof(uint8));
					memcpy(vertexData, data + i, glVertSize);
					buffer<uint8> fragmentData(glFragSize / sizeof(uint8));
					memcpy(fragmentData, data + i + glVertSize, glFragSize);
					data.free();
					if (os::supportsPrecompiledShader(app::OPENGL) && vertexData.size > 0) {
						return app::api->createShader(vertexData, fragmentData, attributes);
					} else {
						return app::api->createShader(vertSource, fragSource, attributes);
					}
				} else {
					i += glVertSourceSize + glFragSourceSize;
				}
				i += glVertSize + glFragSize;
				uint64 metalSize = 0;
				memcpy(&metalSize, data + i, sizeof(uint64));
				i += sizeof(uint64);
				if (app::apiType == app::METAL) {
					if (metalSize == 0) {
						serr("no metal shader data");
						return nullptr;
					}
					buffer<uint8> metalData(metalSize / sizeof(uint8));
					memcpy(metalData, data + i, metalSize);
					data.free();
					return app::api->createShader(metalData, buffer<uint8>(nullptr), attributes);
				}
				i += metalSize;
				if (app::apiType == app::VULKAN) {
					serr("unsupported api");
					data.free();
					return nullptr; // TODO create Vulkan shader from SPIR-V data
				}
				if (app::apiType == app::DX11) {
					serr("unsupported api");
					data.free();
					return nullptr; // TODO support dx11 HLSL
				}
				if (app::apiType == app::DX12) {
					serr("unsupported api");
					data.free();
					return nullptr; // TODO support dx12 HLSL
				}
			} else {
				serr("invalid version of spruce-shader ", file);
			}
			data.free();
			return nullptr;
		}

		Shader* createShader(string& vertSource, string& fragSource, buffer<VertexAttribute> attributes) {
			return app::api->createShader(vertSource, fragSource, attributes);
		}

		PerspectiveCamera* createPerspectiveCamera(float viewportWidth, float viewportHeight, float fieldOfView, float near, float far, vec3f& up, vec3f& dir) {
			return new PerspectiveCamera(viewportWidth, viewportHeight, fieldOfView, near, far, up, dir);
		}

		OrthographicCamera* createOrthographicCamera(float viewportWidth, float viewportHeight, float near, float far, vec3f& up, vec3f& dir) {
			return new OrthographicCamera(viewportWidth, viewportHeight, near, far, up, dir);
		}

		Texture* createTexture(const FileHandle& path) {
			return app::api->createTexture(path);
		}

		Texture* createTexture(Texture::PixelFormat format, buffer<uint8> data, uint16 width, uint16 height) {
			return app::api->createTexture(format, data, width, height);
		}

		RenderTarget* createRenderTarget(Texture::PixelFormat format, uint16 width, uint16 height) {
			return app::api->createRenderTarget(format, width, height);
		}

		void render(Mesh* mesh, Shader* shader, Primitive primitive) {
			getCommandBuffer().add(new cmd::RenderMeshCommand(mesh, shader, primitive));
		}

		void render(buffer<float> vertices, buffer<uint16> indices, Shader* shader, graphics::Primitive primitive) {
			getCommandBuffer().add(new cmd::RenderBufferCommand(vertices, indices, shader, primitive));
		}

		void render(RenderPass* renderPass) {
			getCommandBuffer().add(new cmd::RenderPassCommand(renderPass));
			waitForGraphicsTasks(true);
			renderPass->render();
		}

		void render(string str, Font& font, spruce::color color, vec3f position, quaternion rotation, vec2f size, Camera* camera) {
			mat4f cameraTrans;
			if (camera != nullptr) {
				cameraTrans = camera->combined;
			}
			getCommandBuffer().add(new cmd::RenderFontCommand(str, font, color, position, rotation, size, cameraTrans));
		}

		void renderLine(vec3f a, vec3f b, color colora, color colorb, Camera* camera) {
			mat4f cameraTrans;
			if (camera != nullptr) {
				cameraTrans = camera->combined;
			}
			getCommandBuffer().add(new cmd::RenderLineCommand(a, b, colora, colorb, cameraTrans));
		}

		void renderRect(vec3f pos, vec2f size, color color, quaternion rotation, Camera* camera) {
			mat4f cameraTrans;
			if (camera != nullptr) {
				cameraTrans = camera->combined;
			}
			getCommandBuffer().add(new cmd::RenderRectCommand(pos, size, color, rotation, cameraTrans));
		}

		uint16 getWindowWidth() {
			return app::window->width;
		}

		uint16 getWindowHeight() {
			return app::window->height;
		}

		vec3f getNDCSize() {
			return app::api->ndcSize;
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
