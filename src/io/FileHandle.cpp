#include <io/FileHandle.h>

namespace spruce {
	FileHandle::FileHandle(const unsigned char* path) : FileHandle(string(reinterpret_cast<const char*>(path))) {
	}

	FileHandle::FileHandle(const char* path) : FileHandle(string(path)) {
	}

	FileHandle::FileHandle(string path) {
		absolutePath = path;
		size_t i = absolutePath.rfind('.', absolutePath.length());
		if (i != string::npos) {
			extension = absolutePath.substr(i + 1, absolutePath.length() - i);
			size_t j = absolutePath.rfind('/', absolutePath.length());
			name = absolutePath.substr(j + 1, i - j - 1);
		} else {
			name = "null";
			extension = "null";
		}
		FILE* cfile = fopen(absolutePath.c_str(), "rt");
		if (cfile != NULL) {
			exists = true;
			fseek(cfile, 0, SEEK_END);
			size = ftell(cfile);
			fclose(cfile);
		} else {
			exists = false;
			size = 0;
		}
	}

	FileHandle::~FileHandle() {
	}

	std::ostream& operator<<(std::ostream& stream, const FileHandle& file) {
		stream << file.absolutePath << std::endl;
		return stream;
	}
}
