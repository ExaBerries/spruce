#pragma once
#include <common.h>

namespace spruce {
	class FileHandle {
		public:
			enum FileHandleType {
				INTERNAL, EXTERNAL, ABSOLUTE
			};
			FileHandleType type;
			string absolutePath;
			string name;
			string extension;
			uint64 size;
			bool exists;
			bool directory;

			FileHandle();
			FileHandle(FileHandleType type, const unsigned char* path);
			FileHandle(FileHandleType type, const char* path);
			FileHandle(FileHandleType type, string path);
			virtual ~FileHandle();

			buffer<FileHandle> list();

			friend std::ostream& operator<<(std::ostream& stream, const FileHandle& file);
	};
}
