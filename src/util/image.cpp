#include <util/image.h>
#include <FreeImage.h>

namespace spruce {
	namespace util {
		uint8* loadImage(std::string& path, uint16& width, uint16& height, uint16& bitsPerPixel) {
			const char* pathCStr = path.c_str();
			FREE_IMAGE_FORMAT format = FIF_UNKNOWN;
			FIBITMAP* temp = nullptr;
			format = FreeImage_GetFileType(pathCStr, 0);
			if (format == FIF_UNKNOWN) {
				format = FreeImage_GetFIFFromFilename(pathCStr);
			}
			if (format == FIF_UNKNOWN) {
				return nullptr;
			}
			if (FreeImage_FIFSupportsReading(format)) {
				temp = FreeImage_Load(format, pathCStr);
			}
			FIBITMAP* bitmap = FreeImage_ConvertTo32Bits(temp);
			FreeImage_Unload(temp);
			unsigned char* pixels = FreeImage_GetBits(bitmap);
			width = FreeImage_GetWidth(bitmap);
			height = FreeImage_GetHeight(bitmap);
			bitsPerPixel = FreeImage_GetBPP(bitmap);
			uint16 size = width * height * (bitsPerPixel / 8);
			uint8* data = new uint8[size];
			memcpy(data, pixels, size);
			FreeImage_Unload(bitmap);
			return data;
		}
	}
}
