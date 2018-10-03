#pragma once
#include <common.h>
#include <backend/Window.h>
#include <graphics/Mesh.h>
#include <graphics/Shader.h>
#include <graphics/Texture.h>
#include <graphics/RenderPass.h>
#include <graphics/RenderTarget.h>
#include <graphics/Font.h>
#include <graphics/CommandBuffer.h>
#include <graphics/VertexAttribute.h>
#include <graphics/Primitive.h>
#include <input/input.h>
#include <io/FileHandle.h>
#include <backend/api/batcher/Batcher.h>
#include <backend/api/batcher/FontBatcher.h>
#include <backend/api/batcher/ShapeBatcher.h>

namespace spruce {
	class RenderAPI {
		public:
			Window* window;
			vec3f ndcSize;
			FontBatcher* fontBatcher;
			ShapeBatcher* shapeBatcher;

			RenderAPI(Window* window, vec3f ndcSize);
			virtual ~RenderAPI();

			virtual void createContext() = 0;
			virtual void surfaceCreated() = 0;
			virtual void renderStart() = 0;
			virtual void renderEnd() = 0;

			virtual void render(Mesh* mesh, Shader* shader, graphics::Primitive primitive) = 0;
			virtual void render(buffer<float> vertices, buffer<uint16> indices, Shader* shader, graphics::Primitive primitive) = 0;
			virtual void changeTarget(RenderTarget* target) = 0;
			void render(string str, Font& font, spruce::color color, vec3f position, quaternion rotation, vec2f size, mat4f camera);
			void renderLine(vec3f a, vec3f b, color colora, color colorb, mat4f camera);
			void renderRect(vec3f pos, vec2f size, color color, quaternion rotation, mat4f camera);
			virtual void bind(Mesh* mesh) = 0;
			virtual void bind(Texture* texture) = 0;
			virtual void unbind(Texture* texture) = 0;
			virtual void bind(Shader* shader) = 0;
			virtual void setUniform(Shader* shader, string name, const int32& value) = 0;
			virtual void setUniform(Shader* shader, string name, const vec2i& vector) = 0;
			virtual void setUniform(Shader* shader, string name, const float& value) = 0;
			virtual void setUniform(Shader* shader, string name, const vec2f& vector) = 0;
			virtual void setUniform(Shader* shader, string name, const vec3f& vector) = 0;
			virtual void setUniform(Shader* shader, string name, const mat4f& matrix) = 0;
			virtual void setUniform(Shader* shader, string name, const quaternion& quaternion) = 0;
			virtual void setUniform(Shader* shader, string name, const color& color) = 0;
			virtual void setUniform(Shader* shader, string name, Texture* texture) = 0;
			virtual void setUniform(Shader* shader, string name, graphics::RenderPass* renderPass) = 0;

			virtual Mesh* createMesh(buffer<float> vertices, buffer<uint16> indices) = 0;
			virtual Shader* createShader(buffer<uint8> vertData, buffer<uint8> fragData, buffer<VertexAttribute> attributes) = 0;
			virtual Shader* createShader(string& vertSource, string& fragSource, buffer<VertexAttribute> attributes) = 0;
			virtual Texture* createTexture(const FileHandle& file) = 0;
			virtual Texture* createTexture(Texture::PixelFormat format, buffer<uint8> data, uint16 width, uint16 height) = 0;
			virtual RenderTarget* createRenderTarget(Texture::PixelFormat format, uint16 width, uint16 height) = 0;

			virtual string getGPUVendor() = 0;
			virtual uint16 getAPIVersionMajor() = 0;
			virtual uint16 getAPIVersionMinor() = 0;
			virtual string getAPIRendererName() = 0;

			virtual void setPerspective(mat4f& matrix, float& near, float& far, float& fov, float& aspectRatio) = 0;
			virtual void setOrthographic(mat4f& matrix, float left, float right, float top, float bottom, float near, float far) = 0;
	};
}
