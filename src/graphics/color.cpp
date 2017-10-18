#include <graphics/color.h>

namespace spruce {
	color::color()  : r(0), g(0), b(0), a(0) {
	}

	color::color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {
	}

	color::color(int32 hex) {
		r = ((hex << 32) & 0xFF) / 255.0;
		g = ((hex << 16) & 0xFF) / 255.0;
		b = ((hex << 8) & 0xFF) / 255.0;
		a = (hex & 0xFF) / 255.0;
	}

	color::~color() {
	}
}
