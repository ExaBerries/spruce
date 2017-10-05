#pragma once
#include <iostream>

namespace spruce {
	template <typename TYPE>
	void log(TYPE o) {
		std::cout << o;
	}

	template <typename TYPE>
	void log(std::vector<TYPE> vector) {
		for (TYPE t : vector) {
			std::cout << t;
		}
	}

	template <typename ... TYPES>
	void log(TYPES... args) {
		log(args...);
		std::cout << std::endl;
	}

	void logGLError();
	void logGLError(std::string name);
}
