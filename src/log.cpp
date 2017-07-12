#include <log.h>

namespace spruce {
	void log(std::string string) {
		std::cout << string << std::endl;
	}

	void log(std::vector<char> string) {
		for (std::vector<char>::const_iterator i = string.begin(); i != string.end(); ++i) {
			std::cout << *i;
		}
		std::cout << std::endl;
	}

	void log(char value) {
		std::cout << value << std::endl;
	}

	void log(short value) {
		std::cout << value << std::endl;
	}

	void log(unsigned int value) {
		std::cout << value << std::endl;
	}

	void log(int value) {
		std::cout << value << std::endl;
	}

	void log(long value) {
		std::cout << value << std::endl;
	}

	void log(long long value) {
		std::cout << value << std::endl;
	}

	void logGLError() {
		std::cout << "glError=" << glGetError() << std::endl;
	}
}
