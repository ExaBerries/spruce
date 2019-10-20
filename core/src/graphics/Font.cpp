#include <graphics/Font.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <limits>

namespace spruce {
	namespace graphics {
		Font::Font(FileHandle fileHandle, uint16 size) : fileHandle(fileHandle) {
			texture = nullptr;
			this->size = size;
		}

		Font::~Font() {
			freeVRAM();
		}

		void Font::toVRAM(RendererAbstractor* renderer) {
			FT_Library ft;
			if (FT_Init_FreeType(&ft)) {
				serr("Could not init freetype library");
			}
			FT_Face face;
			if (FT_New_Face(ft, fileHandle.absolutePath.c_str(), 0, &face)) {
				serr("could not open font file");
				return;
			}
			FT_Set_Pixel_Sizes(face, 0, size);
			if (FT_Load_Char(face, 'X', FT_LOAD_RENDER)) {
				serr("Could not load character 'X'");
				return;
			}
			FT_GlyphSlot glyph = face->glyph;
			uint16 width = 0;
			uint16 height = 0;
			for (uint64 i = 0; i < 128; i++) {
				if (FT_Load_Char(face, i, FT_LOAD_RENDER)) {
					serr("character not found: ", i);
					continue;
				}
				width += glyph->bitmap.width;
				if (glyph->bitmap.rows >= std::numeric_limits<uint16>::max()) {
					FT_Done_Face(face);
					FT_Done_FreeType(ft);
					serr("glyph height is to large for uint16");
					return;
				}
				height = std::max(height, static_cast<uint16>(glyph->bitmap.rows));
			}
			uint32 xoff = 0;
			buffer<uint8> data(width * height * sizeof(float));
			buffer<float> fdata = static_cast<buffer<float>>(data);
			for (float& f : fdata) {
				f = 0.5f;
			}
			for (uint16 i = 0; i < 128; i++) {
				if (FT_Load_Char(face, i, FT_LOAD_RENDER)) {
					continue;
				}
				for (uint32 x = 0; x < glyph->bitmap.width; x++) {
					for (uint32 y = 0; y < glyph->bitmap.rows; y++) {
						fdata[x + xoff + y * width] = static_cast<float>(glyph->bitmap.buffer[x + y * glyph->bitmap.width]) / 256.0f;
					}
				}
				chars[i].advance = vec2f(glyph->advance.x, glyph->advance.y) / 64.0f;
				chars[i].size = vec2f(glyph->bitmap.width, glyph->bitmap.rows);
				chars[i].bearing = vec2f(glyph->bitmap_left, glyph->bitmap_top);
				chars[i].texturex = static_cast<float>(xoff) / width;
				xoff += glyph->bitmap.width;
			}
			FT_Done_Face(face);
			FT_Done_FreeType(ft);
			texture = new Texture(Texture::RED, data, width, height);
			texture->toVRAM(renderer);
		}

		Font::CharInfo& Font::getInfoFor(char c) {
			return chars[static_cast<uint16>(c)];
		}

		void Font::freeVRAM() {
			delete texture;
		}
	}
}
