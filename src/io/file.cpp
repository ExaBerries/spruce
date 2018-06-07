#include <io/file.h>

namespace spruce {
	namespace io {
		string readFileTxt(const FileHandle& file) {
			FILE* cfile = fopen(file.absolutePath.c_str(), "rt");
			if (cfile != NULL) {
				fseek(cfile, 0, SEEK_END);
				uint64 length = ftell(cfile);
				char* data = new char[length + 1];
				memset(data, 0, length + 1);
				fseek(cfile, 0, SEEK_SET);
				fread(data, sizeof(char), length, cfile);
				fclose(cfile);
				string result(data);
				delete[] data;
				return result;
			} else {
				serr("could not read file txt ", file);
			}
			return "";
		}

		buffer<uint8> readFileBin(const FileHandle& file) {
			FILE* cfile = fopen(file.absolutePath.c_str(), "rb");
			if (cfile != NULL) {
				fseek(cfile, 0, SEEK_END);
				uint64 length = ftell(cfile);
				buffer<uint8> data(length + 1);
				memset(data, 0, length + 1);
				fseek(cfile, 0, SEEK_SET);
				fread(data, sizeof(uint8), length, cfile);
				fclose(cfile);
				return data;
			} else {
				serr("could not read file bin ", file);
			}
			return nullptr;
		}

		void writeFileTxt(const FileHandle& file, string& string){
			FILE* cfile = fopen(file.absolutePath.c_str(), "wt");
			if (cfile != NULL) {
				fputs(string.c_str(), cfile);
				fclose(cfile);
			} else {
				serr("could not write file txt ", file);
			}
		}

		void writeFileBin(const FileHandle& file, buffer<uint8> data) {
			FILE* cfile = fopen(file.absolutePath.c_str(), "wb");
			if (cfile != NULL) {
				fwrite(data, sizeof(uint8), data.size, cfile);
				fclose(cfile);
			} else {
				serr("could not write file bin ", file);
			}
		}
	}
}
