#pragma once
#include <common.h>
#include <backend/api/opengl/platform.h>
#include <graphics/Texture.h>

namespace spruce {
	class OpenGLTexture: public Texture {
		public:
			GLuint texture;
			uint16 unit;

			OpenGLTexture(PixelFormat format, buffer<uint8> data, uint16& width, uint16& height);
			OpenGLTexture(const OpenGLTexture& texture) = delete;
			~OpenGLTexture();

			void bind();
			void unbind();
			void toVRAM();
			void freeVRAM();
		protected:
			static buffer<bool> units;
			static uint16 getFreeUnit();
	};
}
