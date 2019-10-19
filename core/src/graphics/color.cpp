#include <graphics/color.h>

namespace spruce {
	color::color()  : r(0), g(0), b(0), a(0) {
	}

	color::color(const color& color) : r(color.r), g(color.g), b(color.b), a(color.a) {
	}

	color::color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {
	}

	color::color(int32 hex) {
		r = ((hex >> 24) & 0xFF) / 255.0f;
		g = ((hex >> 16) & 0xFF) / 255.0f;
		b = ((hex >> 8) & 0xFF) / 255.0f;
		a = (hex & 0xFF) / 255.0f;
	}

	color::~color() {
	}

	bool color::operator==(const color& color) const {
		return (r == color.r && g == color.g && b == color.b && a == color.a);
	}

	bool color::operator!=(const color& color) const {
		return (r != color.r || g != color.g || b != color.b || a != color.a);
	}

	std::ostream& operator<<(std::ostream& stream, const color& color) {
		stream << "color(" << color.r << ", " << color.g << ", " << color.b << ", " << color.a << ")";
		return stream;
	}
}
