#pragma once
#include <common.h>
#include <math/mat4f.h>
#include <backend/api/RenderAPI.h>
#include <backend/api/opengl/OpenGLContext.h>
#include <graphics/Screen.h>

namespace spruce {
	namespace app {
		extern graphics::Screen* screen;
	}

	class OpenGL : public RenderAPI {
		public:
			OpenGL(Window* window);
			~OpenGL();

			void init();
			void renderStart();
			void renderEnd();

			string getError();

			Mesh* createMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices);
			Shader* createShader(uint8* vertData, uint16 vertDataSize, uint8* fragData, uint16 fragDataSize, uint16 attributesCount, VertexAttribute* attributes);
			Shader* createShader(string& vertSource, string& fragSource, uint16 attributesCount, VertexAttribute* attributes);
			ShapeRenderer* createShapeRenderer();
			Texture* createTexture(const FileHandle& path);
			Texture* createTexture(Texture::PixelFormat format, uint8* data, uint16 width, uint16 height);
			RenderTarget* createRenderTarget(Texture::PixelFormat format, uint16 width, uint16 height);

			void render(Mesh* mesh, Shader* shader);
			void renderStart(graphics::RenderPass* renderPass);
			void bind(Mesh* mesh);
			void bind(Texture* texture);
			void unbind(Texture* texture);
			void bind(Shader* shader);
			void setUniform(Shader* shader, string name, Shader::ShaderUniformLocation location, const int32& value);
			void setUniform(Shader* shader, string name, Shader::ShaderUniformLocation location, const vec2i& vector);
			void setUniform(Shader* shader, string name, Shader::ShaderUniformLocation location, const float& value);
			void setUniform(Shader* shader, string name, Shader::ShaderUniformLocation location, const vec2f& vector);
			void setUniform(Shader* shader, string name, Shader::ShaderUniformLocation location, const vec3f& vector);
			void setUniform(Shader* shader, string name, Shader::ShaderUniformLocation location, const mat4f& matrix);
			void setUniform(Shader* shader, string name, Shader::ShaderUniformLocation location, const quaternion& quaternion);
			void setUniform(Shader* shader, string name, Shader::ShaderUniformLocation location, const color& color);
			void setUniform(Shader* shader, string name, Shader::ShaderUniformLocation location, const Texture* texture);
			void setUniform(Shader* shader, string name, Shader::ShaderUniformLocation location, const graphics::RenderPass* renderPass);

			void setBlend(bool value);
			void setDepth(bool value);

			string getGPUVendor();
			uint16 getAPIVersionMajor();
			uint16 getAPIVersionMinor();
			string getAPIRendererName();

			void setPerspective(mat4f& matrix, float& near, float& far, float& fov, float& aspectRatio);
			void setOrthographic(mat4f& matrix, float left, float right, float top, float bottom, float near, float far);
	};
}
