#pragma once
#include <common.h>
#include <graphics/renderer/api/opengl/glplatform.h>
#include <graphics/color.h>

namespace spruce {
	namespace graphics {
		class OpenGLShader {
			public:
				GLuint vertShader;
				GLuint fragShader;
				GLuint program;

				OpenGLShader();
				OpenGLShader(const OpenGLShader&) = delete;
				OpenGLShader(OpenGLShader&&) noexcept = delete;
				~OpenGLShader();

				void compileSPIRV(const buffer<uint8>& vertData, const buffer<uint8>& fragData);
				void compileSource(const string& vertStr, const string& fragData);
				void createProgram();
				void bindAttribLocation(uint16 location, string name);
				void bind();
				void setUniform(uint16 location, int32 value);
				void setUniform(uint16 location, float value);
				void setUniform(uint16 location, const vec2f& vector);
				void setUniform(uint16 location, const vec3f& vector);
				void setUniform(uint16 location, const vec4f& vector);
				void setUniform(uint16 location, const mat4f& matrix);
				void setUniform(uint16 location, const color& color);

				OpenGLShader& operator=(const OpenGLShader&) = delete;
				OpenGLShader& operator=(OpenGLShader&&) noexcept = delete;
		};
	}

	using graphics::OpenGLShader;
}
