#pragma once

#ifdef __APPLE__
	#include <OpenGL/gl3.h>
	#include <OpenGL/glext.h>
	#include <OpenGL/gl3ext.h>
	#define GL_SHADER_BINARY_FORMAT_SPIR_V NULL // SPIR-V extension doesn't yet exist on mac
	void glSpecializeShader(GLuint shader, const GLchar* entryPoint, GLuint c, void* d, void* e); // SPIR-V extension doesn't yet exist on mac
#endif

#ifdef __linux__
	#include <GL/glew.h>
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif
