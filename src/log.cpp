#include "log.h"

namespace spruce {
	extern void log(std::string string) {
		std::cout << string << std::endl;
	}

	extern void log(std::vector<char> string) {
		for (std::vector<char>::const_iterator i = string.begin(); i != string.end(); ++i) {
			std::cout << *i;
		}
		std::cout << std::endl;
	}

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
		std::cout << "glError=" << glGetError() << std::endl;
	}

	extern void log(GLuint& value) {
		std::cout << value << std::endl;
	}
}
