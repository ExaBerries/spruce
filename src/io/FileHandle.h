#pragma once
#include <common.h>

namespace spruce {
	class FileHandle {
		public:
			string absolutePath;
			string name;
			string extension;
			uint64 size;
			bool exists;

			FileHandle(const unsigned char* path);
			FileHandle(const char* path);
			FileHandle(string path);
			virtual ~FileHandle();

			friend std::ostream& operator<<(std::ostream& stream, const FileHandle& file);
	};
}
