#pragma once
#include <iostream>
#define FOREACH_VARIADIC(EXPR, ARGS) (int[]){((void)(EXPR(std::forward<TYPES>(ARGS))),0)...,0}

namespace spruce {
	namespace log {
		extern std::mutex logMutex;

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

		template <typename ... TYPES>
		void log(std::string file, uint32_t line, TYPES ... args) {
			std::lock_guard<std::mutex> guard(logMutex);
			FOREACH_VARIADIC(print, args);
			std::cout << std::endl;
		}

		template <typename ... TYPES>
		void err(std::string file, uint32_t line, TYPES ... args) {
			std::lock_guard<std::mutex> guard(logMutex);
			std::cout << file << ":" << line << "\t";
			FOREACH_VARIADIC(print, args);
			std::cout << std::endl;
		}

		void logAPIError();
		void logAPIError(std::string name);
	}

	#define slog(...) spruce::log::log(__FILE__, __LINE__, __VA_ARGS__)
	#define serr(...) spruce::log::err(__FILE__, __LINE__, __VA_ARGS__)
}
