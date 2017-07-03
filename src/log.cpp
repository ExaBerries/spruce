#include "log.h"
#include <iostream>

namespace spruce {
	extern void log(char& value) {
		std::cout << value << std::endl;
	}

	extern void log(short& value) {
		std::cout << value << std::endl;
	}

	extern void log(int& value) {
		std::cout << value << std::endl;
	}

	extern void log(long& value) {
		std::cout << value << std::endl;
	}

	extern void log(long long& value) {
		std::cout << value << std::endl;
	}

	extern void logGLError() {
		// TODO std::cout << "glError=" << glGetError() << std::endl;
	}
}
