#include <io/FileHandle.h>
#include <backend/os.h>

namespace spruce {
	FileHandle::FileHandle(FileHandleType type, const unsigned char* path) : FileHandle(type, string(reinterpret_cast<const char*>(path))) {
	}

	FileHandle::FileHandle(FileHandleType type, const char* path) : FileHandle(type, string(path)) {
	}

	FileHandle::FileHandle(FileHandleType type, string path) {
		this->type = type;
		if (type == INTERNAL) {
			absolutePath = os::getBasePathInternal() + path;
		} else if (type == EXTERNAL) {
			absolutePath = os::getBasePathExternal() + path;
		}
		size_t i = absolutePath.rfind('.', absolutePath.length());
		if (i != string::npos) {
			extension = absolutePath.substr(i + 1, absolutePath.length() - i);
			size_t j = absolutePath.rfind('/', absolutePath.length());
			name = absolutePath.substr(j + 1, i - j - 1);
		} else {
			name = "";
			extension = "";
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
		stream << file.absolutePath;
		return stream;
	}
}
