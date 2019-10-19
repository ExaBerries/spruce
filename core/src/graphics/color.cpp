#include <graphics/color.h>

namespace spruce {
	color::color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {
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
