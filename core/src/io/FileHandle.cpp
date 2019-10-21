#include <io/FileHandle.h>
#include <backend/os.h>
#include <sys/stat.h>

namespace spruce {
	FileHandle::FileHandle() : FileHandle(FileHandle::INTERNAL, "") {
	}

	FileHandle::FileHandle(FileHandleType type, const unsigned char* path) : FileHandle(type, string(reinterpret_cast<const char*>(path))) {
	}

	FileHandle::FileHandle(FileHandleType type, const char* path) : FileHandle(type, string(path)) {
	}

	FileHandle::FileHandle(FileHandleType type, const string& path) {
		this->type = type;
		if (type == INTERNAL) {
			absolutePath = os::getBasePathInternal() + path;
		} else if (type == EXTERNAL) {
			absolutePath = os::getBasePathExternal() + path;
		} else if (type == ABSOLUTE) {
			absolutePath = path;
		}
		if (absolutePath.size() == 0) {
			name = "";
			extension = "";
			size = 0;
			exists = false;
			directory = false;
			return;
		}
		exists = os::exists(absolutePath);
		if (!exists) {
			directory = false;
			size = 0;
			name = "";
			extension = "";
			return;
		}
		directory = os::isDir(absolutePath);
		if (directory) {
			size_t i = absolutePath.rfind('/', absolutePath.length());
			if (i != string::npos) {
				name = absolutePath.substr(i + 1, absolutePath.length() - i);
			} else {
				name = "";
				extension = "";
			}
			size = 0;
		} else {
			size_t i = absolutePath.rfind('.', absolutePath.length());
			if (i != string::npos) {
				extension = absolutePath.substr(i + 1, absolutePath.length() - i);
				size_t j = absolutePath.rfind('/', absolutePath.length());
				name = absolutePath.substr(j + 1, i - j - 1);
			} else {
				size_t j = absolutePath.rfind('/', absolutePath.length());
				name = absolutePath.substr(j + 1, absolutePath.length() - j);
				extension = "";
			}
			FILE* cfile = fopen(absolutePath.c_str(), "rt");
			if (cfile != NULL) {
				fseek(cfile, 0, SEEK_END);
				size = static_cast<uint64>(ftell(cfile));
				fclose(cfile);
			} else {
				size = 0;
				serr("error finding size of file ", absolutePath);
			}
		}
	}

	buffer<FileHandle> FileHandle::list() const {
		if (!directory) {
			return nullptr;
		}
		std::vector<string> subFiles = os::listSubFiles(absolutePath);
		if (subFiles.size() == 0) {
			return nullptr;
		}
		buffer<FileHandle> subPaths(subFiles.size());
		for (uint32 i = 0; i < subFiles.size(); i++) {
			subPaths[i] = FileHandle(FileHandle::ABSOLUTE, absolutePath + ((absolutePath.c_str()[absolutePath.size() - 1] != '/') ? "/" : "") + subFiles[i]);
		}
		return subPaths;
	}

	std::ostream& operator<<(std::ostream& stream, const FileHandle& file) {
		stream << file.absolutePath;
		return stream;
	}
}
