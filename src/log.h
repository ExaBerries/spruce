#pragma once
#include <vector>

typedef std::string string;

namespace spruce {
	void log(string string);
	void log(std::vector<char> string);
	void log(char value);
	void log(short value);
	void log(unsigned int value);
	void log(int value);
	void log(long value);
	void log(long long value);
	void log(void* pointer);
	void log(string name, void* pointer);
	void logGLError();
}
