#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <GLFW/glfw3.h>

namespace spruce {
	void log(std::string string);
	void log(std::vector<char> string);
	void log(char value);
	void log(short value);
	void log(unsigned int value);
	void log(int value);
	void log(long value);
	void log(long long value);
	void logGLError();
}
