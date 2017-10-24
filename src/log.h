#pragma once
#include <iostream>
#define FOREACH_VARIADIC(EXPR, ARGS) (int[]){((void)(EXPR(std::forward<TYPES>(ARGS))),0)...,0}

namespace spruce {
	namespace {
		template <typename TYPE>
		void print(TYPE type) {
			std::cout << type;
		}

		template <typename TYPE>
		void print(std::vector<TYPE> vector) {
			for (TYPE type : vector) {
				print(type);
			}
		}
	}

	template <typename ... TYPES>
	void log(TYPES... args) {
		FOREACH_VARIADIC(print, args);
		std::cout << std::endl;
	}

	void logGLError();
	void logGLError(std::string name);
}
