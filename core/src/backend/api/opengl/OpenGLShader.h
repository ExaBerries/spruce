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

			OpenGLShader(buffer<uint8> vertData, buffer<uint8> fragData, buffer<VertexAttribute> attributes);
			OpenGLShader(const string& vertSource, const string& fragSource, buffer<VertexAttribute> attributes);
			OpenGLShader(const OpenGLShader& shader) = delete;
			~OpenGLShader();

			void compileSPIRV();
			void compileSource();
			void compile(graphics::RenderPass* renderPass);

			uint16 getAttributeLocation(string name);
			void registerUniform(std::string name, ShaderUniformLocation location, uint16 index);
	};
}
