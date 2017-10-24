#include <io/file.h>

namespace spruce {
	namespace io {
		string readFileTxt(const string& filepath) {
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
			return "";
		}

		uint8* readFileBin(const string& filepath, uint32& count) {
			FILE* file = fopen(filepath.c_str(), "rb");
			if (file != NULL) {
				fseek(file, 0, SEEK_END);
				unsigned long length = ftell(file);
				uint8* data = new uint8[length + 1];
				memset(data, 0, length + 1);
				fseek(file, 0, SEEK_SET);
				fread(data, sizeof(uint8), length, file);
				fclose(file);
				count = length;
				return data;
			}
			return nullptr;
		}

		void writeFileTxt(const string& filepath, string& string){
			FILE* file = fopen(filepath.c_str(), "wt");
			if (file != NULL) {
				fputs(string.c_str(), file);
				fclose(file);
			}
		}

		void writeFileBin(const string& filepath, uint8* data, uint32& count) {
			FILE* file = fopen(filepath.c_str(), "wb");
			if (file != NULL) {
				fwrite(data, sizeof(uint8), count, file);
				fclose(file);
			}
		}
	}
}
