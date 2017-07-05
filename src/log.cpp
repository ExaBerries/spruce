#include "log.h"

namespace spruce {
	extern void log(std::string string) {
		std::cout << string << std::endl;
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
}
