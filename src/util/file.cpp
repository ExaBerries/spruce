#include <util/file.h>

namespace spruce {
	namespace util {
		string readFileTxt(const char* filepath) {
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
			return "";
		}

		string readFileTxt(const string& filepath) {
			return readFileTxt(filepath.c_str());
		}

		uint8* readFileBin(const char* filepath) {
			FILE* file = fopen(filepath, "rb");
			if (file != NULL) {
				fseek(file, 0, SEEK_END);
				unsigned long length = ftell(file);
				uint8* data = new uint8[length + 1];
				memset(data, 0, length + 1);
				fseek(file, 0, SEEK_SET);
				fread(data, sizeof(uint8), length, file);
				fclose(file);
				return data;
			}
			return nullptr;
		}

		uint8* readFileBin(const string& filepath) {
			return readFileBin(filepath.c_str());
		}

		void writeFileTxt(const char* filepath, const char* string) {
			FILE* file = fopen(filepath, "wt");
			if (file != NULL) {
				fputs(string, file);
				fclose(file);
			}
		}

		void writeFileTxt(const string& filepath, string& string){
			writeFileTxt(filepath.c_str(), string.c_str());
		}

		void writeFileBin(const char* filepath, uint8* data, uint32& count) {
			FILE* file = fopen(filepath, "wb");
			if (file != NULL) {
				fwrite(data, sizeof(uint8), count, file);
				fclose(file);
			}
		}

		void writeFileBin(const string& filepath, uint8* data, uint32& count) {
			writeFileBin(filepath.c_str(), data, count);
		}
	}
}
