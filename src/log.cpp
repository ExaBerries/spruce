#include <log.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include <stdarg.h>
#include <stdlib.h>

namespace spruce {
	void logGLError() {
		std::cout << "glError=" << glGetError() << std::endl;
	}

	void logGLError(std::string name) {
		std:: cout << name << "=" << glGetError() << std::endl;
	}
}
