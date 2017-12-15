#pragma once
#include <common.h>
#include <graphics/Shader.h>
#include <backend/api/opengl/platform.h>

namespace spruce {
	class OpenGLShader : public Shader {
		public:
			GLuint vert;
			GLuint frag;
			GLuint program;
			std::map<string, uint16> uniformLocations;

			OpenGLShader(const OpenGLShader& shader);
			OpenGLShader(uint8* vertData, uint16 vertDataSize, uint8* fragData, uint16 fragDataSize, uint16 attributesCount, VertexAttribute* attributes);
			OpenGLShader(const string& vertSource, const string& fragSource, uint16 attributesCount, VertexAttribute* attributes);
			~OpenGLShader();

			void compileSPIRV();
			void compileSource();
			void compile(graphics::RenderPass* renderPass);
			void enable();
			void disable();

			uint16 getAttributeLocation(string name);
			uint16 registerUniform(string name, uint16 index);

			void setUniform(string name, const int& value);
			void setUniform(string name, const vec2i& vector);
			void setUniform(string name, const float& value);
			void setUniform(string name, const vec2f& vector);
			void setUniform(string name, const vec3f& vector);
			void setUniform(string name, const mat4f& matrix);
			void setUniform(string name, const quaternion& quaternion);
			void setUniform(string name, const color& color);
			void setUniform(string name, const Texture* texture);
			void setUniform(string name, const graphics::RenderPass* renderPass);
	};
}
