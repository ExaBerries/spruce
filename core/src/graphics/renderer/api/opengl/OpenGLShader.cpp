#include <graphics/renderer/api/opengl/OpenGLShader.h>

namespace spruce {
	namespace graphics {
		OpenGLShader::OpenGLShader() {
			vertShader = 0;
			fragShader = 0;
			program = 0;
		}

		OpenGLShader::~OpenGLShader() {
			glDeleteShader(vertShader);
			glDeleteShader(fragShader);
			glDeleteProgram(program);
		}

		void OpenGLShader::compileSPIRV(buffer<uint8> vertData, buffer<uint8> fragData) {
			vertShader = glCreateShader(GL_VERTEX_SHADER);
			glShaderBinary(1, &vertShader, GL_SHADER_BINARY_FORMAT_SPIR_V, vertData, vertData.size);
			glSpecializeShader(vertShader, "main", 0, nullptr, nullptr);
			GLint vertSuccess = 0;
			glGetShaderiv(vertShader, GL_COMPILE_STATUS, &vertSuccess);
			if (vertSuccess == GL_FALSE) {
				GLint length = 0;
				glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &length);
				GLchar errorLog[length];
				glGetShaderInfoLog(vertShader, length, &length, &errorLog[0]);
				serr("failed to specialize vertex shader:");
				serr(errorLog);
				glDeleteShader(vertShader);
				return;
			}

			fragShader = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderBinary(1, &fragShader, GL_SHADER_BINARY_FORMAT_SPIR_V, fragData, fragData.size);
			glSpecializeShader(fragShader, "main", 0, nullptr, nullptr);
			GLint fragSuccess = 0;
			glGetShaderiv(fragShader, GL_COMPILE_STATUS, &fragSuccess);
			if (fragSuccess == GL_FALSE) {
				GLint length = 0;
				glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &length);
				GLchar errorLog[length];
				glGetShaderInfoLog(fragShader, length, &length, &errorLog[0]);
				serr("failed to specialize fragment shader:");
				serr(errorLog);
				glDeleteShader(fragShader);
				return;
			}
		}

		void OpenGLShader::compileSource(string vertStr, string fragStr) {
			const char* vertCStr = vertStr.c_str();
			vertShader = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertShader, 1, &vertCStr, nullptr);
			glCompileShader(vertShader);
			GLint vertSuccess = 0;
			glGetShaderiv(vertShader, GL_COMPILE_STATUS, &vertSuccess);
			if (vertSuccess == GL_FALSE) {
				GLint length = 0;
				glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &length);
				GLchar errorLog[length];
				glGetShaderInfoLog(vertShader, length, &length, &errorLog[0]);
				serr("failed to compile vertex shader:");
				slog(errorLog);
				glDeleteShader(vertShader);
				return;
			}

			const char* fragCStr = fragStr.c_str();
			fragShader = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fragShader, 1, &fragCStr, nullptr);
			glCompileShader(fragShader);
			GLint fragSuccess = 0;
			glGetShaderiv(fragShader, GL_COMPILE_STATUS, &fragSuccess);
			if (fragSuccess == GL_FALSE) {
				GLint length = 0;
				glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &length);
				GLchar errorLog[length];
				glGetShaderInfoLog(fragShader, length, &length, &errorLog[0]);
				serr("failed to compile fragment shader:");
				serr(errorLog);
				glDeleteShader(fragShader);
				return;
			}
		}

		void OpenGLShader::createProgram() {
			program = glCreateProgram();
			glAttachShader(program, vertShader);
			glAttachShader(program, fragShader);
			glLinkProgram(program);
			GLint linked = GL_FALSE;
			glGetProgramiv(program, GL_LINK_STATUS, &linked);
			if (linked == GL_FALSE) {
				GLint length = 0;
				glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
				GLchar errorLog[length];
				glGetProgramInfoLog(program, length, &length, &errorLog[0]);
				serr("failed to link shader:");
				serr(errorLog);
				glDeleteProgram(program);
				glDeleteShader(vertShader);
				glDeleteShader(fragShader);
				return;
			}
			glValidateProgram(program);
		}

		void OpenGLShader::bindAttribLocation(uint16 location, string name) {
			glBindAttribLocation(program, location, name.c_str());
		}

		void OpenGLShader::bind() {
			glUseProgram(program);
		}

		void OpenGLShader::setUniform(uint16 location, const float& value) {
			glUniform1f(location, value);
		}

		void OpenGLShader::setUniform(uint16 location, const vec2f& vector) {
			glUniform2f(location, vector.x, vector.y);
		}

		void OpenGLShader::setUniform(uint16 location, const vec3f& vector) {
			glUniform3f(location, vector.x, vector.y, vector.z);
		}

		void OpenGLShader::setUniform(uint16 location, const vec4f& vector) {
			glUniform4f(location, vector.x, vector.y, vector.z, vector.w);
		}

		void OpenGLShader::setUniform(uint16 location, const mat4f& matrix) {
			glUniformMatrix4fv(location, 1, GL_TRUE, matrix.values);
		}

		void OpenGLShader::setUniform(uint16 location, const color& color) {
			glUniform4f(location, color.r, color.g, color.b, color.a);
		}
	}
}
