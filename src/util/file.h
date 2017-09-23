#pragma once
#include <common.h>

namespace spruce {
	namespace util {
		string readFileTxt(const char* filepath);
		string readFileTxt(const string& filepath);
		uint8* readFileBin(const char* filepath);
		uint8* readFileBin(const string& filepath);

		void writeFileTxt(const char* filepath, const char* string);
		void writeFileTxt(const string& filepath, string& string);
		void writeFileBin(const char* filepath, uint8* data, uint32& count);
		void writeFileBin(const string& filepath, uint8* data, uint32& count);
	}
}
