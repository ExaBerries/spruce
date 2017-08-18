#include <backend/opengl/OpenGLShader.h>
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include <graphics/Mesh.h>

namespace spruce {
	OpenGLShader::OpenGLShader(string& vertSource, string& fragSource, uint16 attributeCount, VertexAttribute* attributes) : Shader(vertSource, fragSource, attributeCount, attributes) {
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

	void OpenGLShader::compile() {
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
			log(errorLog);
			glDeleteShader(vert);
			return;
		} else {
			log("vertex shader successfully compiled");
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
			log(errorLog);
			glDeleteShader(frag);
			return;
		} else {
			log("fragment shader successfully compiled");
		}

		program = glCreateProgram();
		glAttachShader(program, vert);
		glAttachShader(program, frag);
		for (int i = 0; i < attributeCount; i++) {
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
			log(errorLog);
			glDeleteProgram(program);
			glDeleteShader(vert);
			glDeleteShader(frag);
			return;
		} else {
			log("shader successfully linked");
		}
		glValidateProgram(program);
	}

	void OpenGLShader::enable() {
		glUseProgram(program);
	}

	void OpenGLShader::disable() {
		glUseProgram(0);
	}

	uint16 OpenGLShader::getAttributeLocation(std::string name) {
		return glGetAttribLocation(program, name.c_str());
	}

	uint16 OpenGLShader::registerUniform(std::string name) {
		int location = glGetUniformLocation(program, name.c_str());
		uniformLocations[name] = location;
		return location;
	}

	void OpenGLShader::setUniform(string name, int& value) {
		glUniform1i(uniformLocations[name], value);
	}

	void OpenGLShader::setUniform(string name, vec2i& vector) {
		glUniform2i(uniformLocations[name], vector.x, vector.y);
	}

	void OpenGLShader::setUniform(string name, float& value) {
		glUniform1f(uniformLocations[name], value);
	}

	void OpenGLShader::setUniform(string name, vec2f& vector) {
		glUniform2f(uniformLocations[name], vector.x, vector.y);
	}

	void OpenGLShader::setUniform(string name, vec3f& vector) {
		glUniform3f(uniformLocations[name], vector.x, vector.y, vector.z);
	}

	void OpenGLShader::setUniform(string name, mat4f& matrix) {
		glUniformMatrix4fv(uniformLocations[name], 1, GL_TRUE, matrix.values);
	}

	void OpenGLShader::setUniform(string name, quaternion& quaternion) {
		glUniform4f(uniformLocations[name], quaternion.x, quaternion.y, quaternion.z, quaternion.w);
	}
}
