#include <graphics/Font.h>
#include <math/math.h>
#include <graphics/graphics.h>
#include <ft2build.h>
#include FT_FREETYPE_H

namespace spruce {
	Font::Font(FileHandle fileHandle) : fileHandle(fileHandle) {
		texture = nullptr;
	}

	Font::~Font() {
		if (texture != nullptr) {
			texture->freeVRAM();
			delete texture;
		}
	}

	void Font::toVRAM() {
		FT_Library ft;
		if (FT_Init_FreeType(&ft)) {
			serr("Could not init freetype library");
		}
		FT_Face face;
		if (FT_New_Face(ft, fileHandle.absolutePath.c_str(), 0, &face)) {
			serr("could not open font file");
			return;
		}
		FT_Set_Pixel_Sizes(face, 0, 48);
		if (FT_Load_Char(face, 'X', FT_LOAD_RENDER)) {
			serr("Could not load character 'X'");
			return;
		}
		FT_GlyphSlot g = face->glyph;
		uint16 width = 0;
		uint16 height = 0;
		for (int32 i = 0; i < 128; i++) {
			if (FT_Load_Char(face, i, FT_LOAD_RENDER)) {
				serr("character not found: ", i);
				continue;
			}
			width += g->bitmap.width;
			height = std::max((uint32) height, g->bitmap.rows);
		}
		uint32 xoff = 0;
		buffer<uint8> data(width * height * sizeof(float));
		buffer<float> fdata = (buffer<float>) data;
		for (uint32 i = 0; i < width * height; i++) {
			fdata[i] = 0.5f;
		}
		for (uint16 i = 0; i < 128; i++) {
			if (FT_Load_Char(face, i, FT_LOAD_RENDER)) {
				continue;
			}
			for (uint32 x = 0; x < g->bitmap.width; x++) {
				for (uint32 y = 0; y < g->bitmap.rows; y++) {
					fdata[x + xoff + y * width] = (float) g->bitmap.buffer[x + y * g->bitmap.width] / 256.0;
				}
			}
			chars[i].ax = g->advance.x >> 6;
			chars[i].ay = g->advance.y >> 6;
			chars[i].bw = g->bitmap.width;
			chars[i].bh = g->bitmap.rows;
			chars[i].bl = g->bitmap_left;
			chars[i].bt = g->bitmap_top;
			chars[i].tx = (float) xoff / width;
			xoff += g->bitmap.width;
		}
		texture = graphics::createTexture(Texture::RED, data, width, height);
		texture->toVRAM();
		FT_Done_Face(face);
		FT_Done_FreeType(ft);
	}
}
