#include <backend/api/opengl/OpenGLShader.h>
#include <graphics/Mesh.h>
#include <backend/api/opengl/OpenGLTexture.h>
#include <backend/api/opengl/OpenGLRenderTarget.h>
#include <backend/api/opengl/platform.h>

namespace spruce {
	OpenGLShader::OpenGLShader(buffer<uint8> vertData, buffer<uint8> fragData, buffer<VertexAttribute> attributes) : Shader(vertData, fragData, attributes) {
		vert = 0;
		frag = 0;
		program = 0;
		this->uniformLocations = std::map<string, uint16>();
	}

	OpenGLShader::OpenGLShader(const string& vertSource, const string& fragSource, buffer<VertexAttribute> attributes) : Shader(vertSource, fragSource, attributes) {
		vert = 0;
		frag = 0;
		program = 0;
		this->uniformLocations = std::map<string, uint16>();
	}

	OpenGLShader::~OpenGLShader() {
		glDeleteShader(vert);
		glDeleteShader(frag);
		glDeleteProgram(program);
		uniformLocations.clear();
	}

	void OpenGLShader::compileSPIRV() {
		vert = glCreateShader(GL_VERTEX_SHADER);
		glShaderBinary(1, &vert, GL_SHADER_BINARY_FORMAT_SPIR_V, vertData, vertData.size);
		glSpecializeShader(vert, "main", 0, nullptr, nullptr);
		GLint vertSuccess = 0;
		glGetShaderiv(vert, GL_COMPILE_STATUS, &vertSuccess);
		if (vertSuccess == GL_FALSE) {
			GLint length = 0;
			glGetShaderiv(vert, GL_INFO_LOG_LENGTH, &length);
			std::vector<GLchar> errorLog(2048);
			glGetShaderInfoLog(vert, length, &length, &errorLog[0]);
			serr(errorLog);
			glDeleteShader(vert);
			return;
		} else {
			#ifdef SHDR_SUCCESS_LOG
				slog("vertex shader successfully specialized");
			#endif
		}

		frag = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderBinary(1, &frag, GL_SHADER_BINARY_FORMAT_SPIR_V, fragData, fragData.size);
		glSpecializeShader(frag, "main", 0, nullptr, nullptr);
		GLint fragSuccess = 0;
		glGetShaderiv(frag, GL_COMPILE_STATUS, &fragSuccess);
		if (fragSuccess == GL_FALSE) {
			GLint length = 0;
			glGetShaderiv(frag, GL_INFO_LOG_LENGTH, &length);
			std::vector<GLchar> errorLog(2048);
			glGetShaderInfoLog(frag, length, &length, &errorLog[0]);
			serr(errorLog);
			glDeleteShader(frag);
			return;
		} else {
			#ifdef SHDR_SUCCESS_LOG
				slog("fragment shader successfully specialized");
			#endif
		}
	}

	void OpenGLShader::compileSource() {
		const char* vertCStr = vertSource.c_str();
		vert = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vert, 1, &vertCStr, NULL);
		glCompileShader(vert);
		GLint vertSuccess = 0;
		glGetShaderiv(vert, GL_COMPILE_STATUS, &vertSuccess);
		if (vertSuccess == GL_FALSE) {
			GLint length = 0;
			glGetShaderiv(vert, GL_INFO_LOG_LENGTH, &length);
			std::vector<GLchar> errorLog(2048);
			glGetShaderInfoLog(vert, length, &length, &errorLog[0]);
			slog(errorLog);
			glDeleteShader(vert);
			return;
		} else {
			#ifdef SHDR_SUCCESS_LOG
				slog("vertex shader successfully compiled");
			#endif
		}

		const char* fragCStr = fragSource.c_str();
		frag = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(frag, 1, &fragCStr, NULL);
		glCompileShader(frag);
		GLint fragSuccess = 0;
		glGetShaderiv(frag, GL_COMPILE_STATUS, &fragSuccess);
		if (fragSuccess == GL_FALSE) {
			GLint length = 0;
			glGetShaderiv(frag, GL_INFO_LOG_LENGTH, &length);
			std::vector<GLchar> errorLog(2048);
			glGetShaderInfoLog(frag, length, &length, &errorLog[0]);
			serr(errorLog);
			glDeleteShader(frag);
			return;
		} else {
			#ifdef SHDR_SUCCESS_LOG
				slog("fragment shader successfully compiled");
			#endif
		}
	}

	void OpenGLShader::compile(graphics::RenderPass* renderPass) {
		if (vertData == nullptr) {
			compileSource();
		} else {
			compileSPIRV();
		}
		program = glCreateProgram();
		glAttachShader(program, vert);
		glAttachShader(program, frag);
		for (int i = 0; i < attributes.size; i++) {
			glBindAttribLocation(program, i, attributes[i].name.c_str());
		}
		glLinkProgram(program);
		GLint linked = GL_FALSE;
		glGetProgramiv(program, GL_LINK_STATUS, &linked);
		if (linked == GL_FALSE) {
			GLint length = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
			std::vector<GLchar> errorLog(2048);
			glGetProgramInfoLog(program, length, &length, &errorLog[0]);
			serr(errorLog);
			glDeleteProgram(program);
			glDeleteShader(vert);
			glDeleteShader(frag);
			return;
		} else {
			#ifdef SHDR_SUCCESS_LOG
				slog("shader successfully linked");
			#endif
		}
		glValidateProgram(program);
	}

	uint16 OpenGLShader::getAttributeLocation(std::string name) {
		return glGetAttribLocation(program, name.c_str());
	}

	uint16 OpenGLShader::registerUniform(std::string name, uint16 index) {
		uint16 location = glGetUniformLocation(program, name.c_str());
		uniformLocations[name] = location;
		return location;
	}
}
