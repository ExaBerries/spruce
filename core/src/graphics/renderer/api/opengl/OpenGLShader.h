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

				void compileSPIRV(const buffer<uint8>& vertData, const buffer<uint8>& fragData) noexcept;
				void compileSource(const string& vertStr, const string& fragStr) noexcept;
				void createProgram() noexcept;
				void bindAttribLocation(uint16 location, const string& name) noexcept;
				void bind() noexcept;
				void setUniform(uint16 location, int32 value) noexcept;
				void setUniform(uint16 location, float value) noexcept;
				void setUniform(uint16 location, const vec2f& vector) noexcept;
				void setUniform(uint16 location, const vec3f& vector) noexcept;
				void setUniform(uint16 location, const vec4f& vector) noexcept;
				void setUniform(uint16 location, const mat4f& matrix) noexcept;
				void setUniform(uint16 location, const color& color) noexcept;

				OpenGLShader& operator=(const OpenGLShader&) = delete;
				OpenGLShader& operator=(OpenGLShader&&) noexcept = delete;
		};
	}

	using graphics::OpenGLShader;
}
