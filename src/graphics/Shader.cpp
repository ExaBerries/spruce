#include "Shader.h"
#include "Mesh.h"
#include <string>
#include <vector>
#include "../log.h"

namespace spruce {
	Shader::Shader(char* vertSource, char* fragSource, int attributesCount, VertexAttribute* attributes) {
		vert = 0;
		frag = 0;
		program = 0;
		this->vertSource = vertSource;
		this->fragSource = fragSource;
		this->attributesCount = attributesCount;
		this->attributes = attributes;
	}

	Shader::~Shader() {
		glDeleteShader(vert);
		glDeleteShader(frag);
		glDeleteProgram(program);
	}

	void Shader::compile() {
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
		for (int i = 0; i < attributesCount; i++) {
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

	void Shader::enable() {
		glUseProgram(program);
	}

	void Shader::disable() {
		glUseProgram(0);
	}

	void Shader::render(Mesh& mesh) {
		mesh.bind();
		for (int i = 0; i < attributesCount; i++) {
			glEnableVertexAttribArray(getAttributeLocation(attributes[i].name));
		}
		if (mesh.ibo > 0) {
			glDrawElements(GL_TRIANGLES, mesh.indexCount, GL_UNSIGNED_SHORT, 0);
		} else {
			glDrawArrays(GL_TRIANGLES, 0, mesh.indexCount);
		}
		for (int i = 0; i < attributesCount; i++) {
			glDisableVertexAttribArray(getAttributeLocation(attributes[i].name));
		}
		mesh.unbind();
	}

	int Shader::getAttributeLocation(std::string name) {
		return glGetAttribLocation(program, name.c_str());
	}
}
