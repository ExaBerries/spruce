#include <graphics/Texture.h>

namespace spruce {
	Texture::~Texture() {
		delete data;
	}
}
