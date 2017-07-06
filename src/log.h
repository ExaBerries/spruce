#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <GLFW/glfw3.h>

namespace spruce {
	extern void log(std::string string);
	extern void log(std::vector<char> string);
	extern void log(char& value);
	extern void log(short& value);
	extern void log(int& value);
	extern void log(long& value);
	extern void log(long long& value);
	extern void logGLError();
	extern void log(GLuint& value);
}
