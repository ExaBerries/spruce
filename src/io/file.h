#pragma once
#include <common.h>

namespace spruce {
	namespace io {
		string readFileTxt(const string& filepath);
		uint8* readFileBin(const string& filepath, uint32& count);
		void writeFileTxt(const string& filepath, string& string);
		void writeFileBin(const string& filepath, uint8* data, uint32& count);
	}
}
