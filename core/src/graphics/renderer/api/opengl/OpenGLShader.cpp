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

		void OpenGLShader::compileSPIRV(const buffer<uint8>& vertData, const buffer<uint8>& fragData) noexcept {
			vertShader = glCreateShader(GL_VERTEX_SHADER);
			glShaderBinary(1, &vertShader, GL_SHADER_BINARY_FORMAT_SPIR_V, vertData, static_cast<GLsizei>(vertData.size));
			glSpecializeShader(vertShader, "main", 0, nullptr, nullptr);
			GLint vertSuccess = 0;
			glGetShaderiv(vertShader, GL_COMPILE_STATUS, &vertSuccess);
			if (vertSuccess == GL_FALSE) {
				GLint length = 0;
				glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &length);
				buffer<GLchar> errorLog(static_cast<uint64>(length));
				glGetShaderInfoLog(vertShader, length, &length, &errorLog[0]);
				serr("failed to specialize vertex shader:");
				serr(errorLog.data);
				glDeleteShader(vertShader);
				errorLog.free();
				return;
			}

			fragShader = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderBinary(1, &fragShader, GL_SHADER_BINARY_FORMAT_SPIR_V, fragData, static_cast<GLsizei>(fragData.size));
			glSpecializeShader(fragShader, "main", 0, nullptr, nullptr);
			GLint fragSuccess = 0;
			glGetShaderiv(fragShader, GL_COMPILE_STATUS, &fragSuccess);
			if (fragSuccess == GL_FALSE) {
				GLint length = 0;
				glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &length);
				buffer<GLchar> errorLog(static_cast<uint64>(length));
				glGetShaderInfoLog(fragShader, length, &length, &errorLog[0]);
				serr("failed to specialize fragment shader:");
				serr(errorLog.data);
				glDeleteShader(fragShader);
				errorLog.free();
				return;
			}
		}

		void OpenGLShader::compileSource(const string& vertStr, const string& fragStr) noexcept {
			const char* vertCStr = vertStr.c_str();
			vertShader = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertShader, 1, &vertCStr, nullptr);
			glCompileShader(vertShader);
			GLint vertSuccess = 0;
			glGetShaderiv(vertShader, GL_COMPILE_STATUS, &vertSuccess);
			if (vertSuccess == GL_FALSE) {
				GLint length = 0;
				glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &length);
				buffer<GLchar> errorLog(static_cast<uint64>(length));
				glGetShaderInfoLog(vertShader, length, &length, &errorLog[0]);
				serr("failed to compile vertex shader:");
				slog(errorLog.data);
				glDeleteShader(vertShader);
				errorLog.free();
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
				buffer<GLchar> errorLog(static_cast<uint64>(length));
				glGetShaderInfoLog(fragShader, length, &length, &errorLog[0]);
				serr("failed to compile fragment shader:");
				serr(errorLog.data);
				glDeleteShader(fragShader);
				errorLog.free();
				return;
			}
		}

		void OpenGLShader::createProgram() noexcept {
			program = glCreateProgram();
			glAttachShader(program, vertShader);
			glAttachShader(program, fragShader);
			glLinkProgram(program);
			GLint linked = GL_FALSE;
			glGetProgramiv(program, GL_LINK_STATUS, &linked);
			if (linked == GL_FALSE) {
				GLint length = 0;
				glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
				buffer<GLchar> errorLog(static_cast<uint64>(length));
				glGetProgramInfoLog(program, length, &length, &errorLog[0]);
				serr("failed to link shader:");
				serr(errorLog.data);
				glDeleteProgram(program);
				glDeleteShader(vertShader);
				glDeleteShader(fragShader);
				errorLog.free();
				return;
			}
			glValidateProgram(program);
		}

		void OpenGLShader::bindAttribLocation(uint16 location, const string& name) noexcept {
			glBindAttribLocation(program, location, name.c_str());
		}

		void OpenGLShader::bind() noexcept {
			glUseProgram(program);
		}

		void OpenGLShader::setUniform(uint16 location, int32 value) noexcept {
			glUniform1i(location, value);
		}

		void OpenGLShader::setUniform(uint16 location, float value) noexcept {
			glUniform1f(location, value);
		}

		void OpenGLShader::setUniform(uint16 location, const vec2f& vector) noexcept {
			glUniform2f(location, vector.x, vector.y);
		}

		void OpenGLShader::setUniform(uint16 location, const vec3f& vector) noexcept {
			glUniform3f(location, vector.x, vector.y, vector.z);
		}

		void OpenGLShader::setUniform(uint16 location, const vec4f& vector) noexcept {
			glUniform4f(location, vector.x, vector.y, vector.z, vector.w);
		}

		void OpenGLShader::setUniform(uint16 location, const mat4f& matrix) noexcept {
			glUniformMatrix4fv(location, 1, GL_TRUE, matrix.values);
		}

		void OpenGLShader::setUniform(uint16 location, const color& color) noexcept {
			glUniform4f(location, color.r, color.g, color.b, color.a);
		}
	}
}
