#pragma once
#include <common.h>
#include <OpenGL/gl3.h>
#include <graphics/Texture.h>

namespace spruce {
	class OpenGLTexture: public Texture {
		public:
			GLuint texture;

			OpenGLTexture(uint8* data, uint16& width, uint16& height, uint16& bitsPerPixel);
			OpenGLTexture(const OpenGLTexture& texture);
			~OpenGLTexture();

			void bind(uint16 unit);
			void toVRAM();
			void freeVRAM();
	};
}
