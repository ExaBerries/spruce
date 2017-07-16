#include <util/file.h>

namespace spruce {
	namespace util {
		string readFile(const char* filepath) {
			FILE* file = fopen(filepath, "rt");
			if (file != NULL) {
				fseek(file, 0, SEEK_END);
				unsigned long length = ftell(file);
				char* data = new char[length + 1];
				memset(data, 0, length + 1);
				fseek(file, 0, SEEK_SET);
				fread(data, sizeof(char), length, file);
				fclose(file);
				string result(data);
				delete[] data;
				return result;
			}
			return ":(";
		}

		string readFile(const string& filepath) {
			FILE* file = fopen(filepath.c_str(), "rt");
			if (file != NULL) {
				fseek(file, 0, SEEK_END);
				unsigned long length = ftell(file);
				char* data = new char[length + 1];
				memset(data, 0, length + 1);
				fseek(file, 0, SEEK_SET);
				fread(data, sizeof(char), length, file);
				fclose(file);
				string result(data);
				delete[] data;
				return result;
			}
			return ":(";
		}
	}
}
