#pragma once
#include <common.h>
#include <backend/api/RenderAPI.h>
#include <graphics/Screen.h>
#include <math/mat/mat4f.h>

namespace spruce {
	class OpenGL : public RenderAPI {
		public:
			OpenGL(Window* window);
			~OpenGL();

			void init();
			void renderStart();
			void renderEnd();

			Mesh* createMesh(buffer<float> vertices, buffer<uint16> indices);
			Shader* createShader(buffer<uint8> vertData, buffer<uint8> fragData, buffer<VertexAttribute> attributes);
			Shader* createShader(string& vertSource, string& fragSource, buffer<VertexAttribute> attributes);
			Texture* createTexture(const FileHandle& path);
			Texture* createTexture(Texture::PixelFormat format, buffer<uint8> data, uint16 width, uint16 height);
			RenderTarget* createRenderTarget(Texture::PixelFormat format, uint16 width, uint16 height);

			void render(Mesh* mesh, Shader* shader, graphics::Primitive primitive);
			void render(buffer<float> vertices, buffer<uint16> indices, Shader* shader, graphics::Primitive primitive);
			void changeTarget(RenderTarget* target);
			void bind(Mesh* mesh);
			void bind(Texture* texture);
			void unbind(Texture* texture);
			void bind(Shader* shader);
			void setUniform(Shader* shader, string name, const int32& value);
			void setUniform(Shader* shader, string name, const vec2i& vector);
			void setUniform(Shader* shader, string name, const float& value);
			void setUniform(Shader* shader, string name, const vec2f& vector);
			void setUniform(Shader* shader, string name, const vec3f& vector);
			void setUniform(Shader* shader, string name, const mat4f& matrix);
			void setUniform(Shader* shader, string name, const quaternion& quaternion);
			void setUniform(Shader* shader, string name, const color& color);
			void setUniform(Shader* shader, string name, Texture* texture);
			void setUniform(Shader* shader, string name, graphics::RenderPass* renderPass);

			string getGPUVendor();
			uint16 getAPIVersionMajor();
			uint16 getAPIVersionMinor();
			string getAPIRendererName();

			void setPerspective(mat4f& matrix, float& near, float& far, float& fov, float& aspectRatio);
			void setOrthographic(mat4f& matrix, float left, float right, float top, float bottom, float near, float far);
	};
}
