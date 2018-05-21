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

			uint16 getAttributeLocation(string name);
			uint16 registerUniform(string name, uint16 index);
	};
}
