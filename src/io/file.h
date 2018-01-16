#pragma once
#include <common.h>
#include <io/FileHandle.h>

namespace spruce {
	namespace io {
		string readFileTxt(const FileHandle& file);
		uint8* readFileBin(const FileHandle& file, uint32& count);
		void writeFileTxt(const FileHandle& file, string& string);
		void writeFileBin(const FileHandle& file, uint8* data, uint32& count);
	}
}
