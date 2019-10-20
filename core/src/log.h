#pragma once
#include <types.h>
#include <iostream>
#include <mutex>
#include <vector>

namespace spruce {
	namespace log {
		extern std::mutex logMutex;

		template <typename ... TYPES>
		void log(const string& file, uint32_t line, TYPES ... args) {
			std::lock_guard<std::mutex> guard(logMutex);
			std::cout << file << ":" << line << "\t";
			(std::cout << ... << args);
			std::cout << std::endl;
		}

		template <typename ... TYPES>
		void err(const string& file, uint32_t line, TYPES ... args) {
			std::lock_guard<std::mutex> guard(logMutex);
			std::cout << file << ":" << line << "\t";
			(std::cout << ... << args);
			std::cout << std::endl;
		}
	}

	#define slog(...) spruce::log::log(__FILE__, __LINE__, __VA_ARGS__)
	#define serr(...) spruce::log::err(__FILE__, __LINE__, __VA_ARGS__)
}
