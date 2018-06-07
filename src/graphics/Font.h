#pragma once
#include <common.h>
#include <graphics/Texture.h>
#include <io/FileHandle.h>

namespace spruce {
	class Font {
		public:
			struct charInfo {
				float ax;
				float ay;
				float bw;
				float bh;
				float bl;
				float bt;
				float tx;
			} chars[128];
			FileHandle fileHandle;
			Texture* texture;

			Font(FileHandle fileHandle);
			Font(const Font& font) = delete;
			virtual ~Font();

			void toVRAM();
	};
}
