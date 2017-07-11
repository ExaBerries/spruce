#include "OpenGLShader.h"
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include "../../log.h"
#include "../../graphics/Mesh.h"

namespace spruce {
	OpenGLShader::OpenGLShader(char* vertSource, char* fragSource, int attributesCount, VertexAttribute* attributes) : Shader(vertSource, fragSource, attributesCount, attributes) {
		vert = 0;
		frag = 0;
		program = 0;
	}

	OpenGLShader::~OpenGLShader() {
		glDeleteShader(vert);
		glDeleteShader(frag);
		glDeleteProgram(program);
	}

	void OpenGLShader::compile() {
		vert = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vert, 1, &vertSource, NULL);
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

		frag = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(frag, 1, &fragSource, NULL);
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

	void OpenGLShader::render(Mesh& mesh) {
		mesh.bind();
		for (int i = 0; i < attributeCount; i++) {
			glEnableVertexAttribArray(getAttributeLocation(attributes[i].name));
		}
		if (mesh.indexCount > 0) {
			glDrawElements(GL_TRIANGLES, mesh.indexCount, GL_UNSIGNED_SHORT, 0);
		} else {
			glDrawArrays(GL_TRIANGLES, 0, mesh.indexCount);
		}
		for (int i = 0; i < attributeCount; i++) {
			glDisableVertexAttribArray(getAttributeLocation(attributes[i].name));
		}
		mesh.unbind();
	}

	unsigned int OpenGLShader::getAttributeLocation(std::string name) {
		return glGetAttribLocation(program, name.c_str());
	}

	unsigned int OpenGLShader::registerUniform(std::string name) {
		int location = glGetUniformLocation(program, name.c_str());
		uniformLocations[name] = location;
		return location;
	}

	void OpenGLShader::setUniform(std::string name, int& value) {
		glUniform1i(uniformLocations[name], value);
	}

	void OpenGLShader::setUniform(std::string name, vec2i& vector) {
		glUniform2i(uniformLocations[name], vector.x, vector.y);
	}

	void OpenGLShader::setUniform(std::string name, float& value) {
		glUniform1f(uniformLocations[name], value);
	}

	void OpenGLShader::setUniform(std::string name, vec2f& vector) {
		glUniform2f(uniformLocations[name], vector.x, vector.y);
	}

	void OpenGLShader::setUniform(std::string name, vec3f& vector) {
		glUniform3f(uniformLocations[name], vector.x, vector.y, vector.z);
	}

	void OpenGLShader::setUniform(std::string name, mat4f& matrix) {
		glUniform4fv(uniformLocations[name], GL_FALSE, matrix.values);
	}

	void OpenGLShader::setUniform(std::string name, quaternion& quaternion) {
		glUniform4f(uniformLocations[name], quaternion.x, quaternion.y, quaternion.z, quaternion.w);

	}
}
