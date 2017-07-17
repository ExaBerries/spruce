#include <util/image.h>
#include <FreeImagePlus.h>

namespace spruce {
	namespace util {
		uint8* loadImage(string& path, uint16& width, uint16& height, uint16& bitsPerPixel) {
			const char* pathCStr = path.c_str();
			FREE_IMAGE_FORMAT format = FIF_UNKNOWN;
			FIBITMAP* temp = nullptr;
			format = FreeImage_GetFileType(pathCStr, 0);
			if (format == FIF_UNKNOWN) {
				log("unknown image format " + path);
				format = FreeImage_GetFIFFromFilename(pathCStr);
			}
			if (format == FIF_UNKNOWN) {
				log("unknown image format " + path);
				return nullptr;
			}
			if (FreeImage_FIFSupportsReading(format)) {
				temp = FreeImage_Load(format, pathCStr);
				FIBITMAP* bitmap = FreeImage_ConvertTo32Bits(temp);
				FreeImage_Unload(temp);
				uint8* pixels = FreeImage_GetBits(bitmap);
				width = FreeImage_GetWidth(bitmap);
				height = FreeImage_GetHeight(bitmap);
				bitsPerPixel = FreeImage_GetBPP(bitmap);
				uint8* data = new uint8[width * height];
				memcpy(data, pixels, width * height * 4);
				FreeImage_Unload(bitmap);
				return data;
			}
			log("unsuppored file format " + path);
			return nullptr;
		}
	}
}
