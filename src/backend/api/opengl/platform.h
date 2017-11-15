#pragma once

#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/gl3.h>
	#define GL_SHADER_BINARY_FORMAT_SPIR_V NULL // SPIR-V extension doesn't yet exist on mac
	void glSpecializeShader(GLuint shader, const GLchar* entryPoint, GLuint c, void* d, void* e); // SPIR-V extension doesn't yet exist on mac
#endif
