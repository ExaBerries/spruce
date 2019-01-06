#pragma once
#include <common.h>
#include <graphics/Texture.h>
#include <io/FileHandle.h>

namespace spruce {
	namespace graphics {
		class Font {
			public:
				struct CharInfo {
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
				uint16 size;

				Font(FileHandle fileHandle, uint16 size);
				Font(const Font& font) = delete;
				Font(Font&&) noexcept = delete;
				~Font();

				void toVRAM(RendererAbstractor* renderer);
				void freeVRAM();

				Font& operator=(const Font&) = delete;
				Font& operator=(Font&&) = delete;
		};
	}

	using graphics::Font;
}
