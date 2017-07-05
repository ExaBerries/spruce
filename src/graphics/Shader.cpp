#include "Shader.h"

namespace spruce {
	Shader::Shader(char* vertSource, char* fragSource) {
		vert = 0;
		frag = 0;
		program = 0;
		this->vertSource = vertSource;
		this->fragSource = fragSource;
	}

	Shader::~Shader() {
		delete[] vertSource;
		delete[] fragSource;
	}

	void Shader::compile() {
		vert = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vert, 1, &vertSource, NULL);
		glCompileShader(vert);

		frag = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(frag, 1, &fragSource, NULL);
		glCompileShader(frag);

		program = glCreateProgram();
		glAttachShader(program, vert);
		glAttachShader(program, frag);
		glLinkProgram(program);
	}
}
