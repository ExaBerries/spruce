#pragma once
#include <common.h>
#include <graphics/Texture.h>
#include <io/FileHandle.h>

namespace spruce {
	namespace graphics {
		class Font {
			public:
				struct CharInfo {
					vec2f advance;
					vec2f size;
					vec2f bearing;
					float texturex;
				} chars[128];
				FileHandle fileHandle;
				owner<Texture> texture;
				uint16 size;

				Font(const FileHandle& fileHandle, uint16 size);
				Font(const Font& font) = delete;
				Font(Font&&) noexcept = delete;
				~Font();

				[[nodiscard]] CharInfo& getInfoFor(char c) noexcept;

				void toVRAM(RendererAbstractor* renderer) noexcept;
				void freeVRAM() noexcept;

				Font& operator=(const Font&) = delete;
				Font& operator=(Font&&) = delete;
		};
	}

	using graphics::Font;
}
