#pragma once

namespace spruce {
	constexpr color::color(int32 hex) {
		r = ((hex >> 24) & 0xFF) / 255.0f;
		g = ((hex >> 16) & 0xFF) / 255.0f;
		b = ((hex >> 8) & 0xFF) / 255.0f;
		a = (hex & 0xFF) / 255.0f;
	}
}
