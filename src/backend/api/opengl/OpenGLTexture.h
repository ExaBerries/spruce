#pragma once
#include <common.h>
#include <backend/api/opengl/platform.h>
#include <graphics/Texture.h>

namespace spruce {
	class OpenGLTexture: public Texture {
		public:
			GLuint texture;
			uint16 unit;

			OpenGLTexture(PixelFormat format, uint8* data, uint16& width, uint16& height);
			OpenGLTexture(const OpenGLTexture& texture);
			~OpenGLTexture();

			void bind();
			void unbind();
			void toVRAM();
			void freeVRAM();
		protected:
			static int32 maxUnit;
			static bool* units;
			static uint16 getFreeUnit();
	};
}
