#pragma once
#include <common.h>

namespace spruce {
	namespace util {
		string readFile(const char* filepath);
		string readFile(const string& filepath);
	}
}
