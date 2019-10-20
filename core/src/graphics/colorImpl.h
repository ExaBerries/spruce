#pragma once

namespace spruce {
	constexpr color::color(int32 hex) {
		r = static_cast<float>((hex >> 24) & 0xFF) / 255.0f;
		g = static_cast<float>((hex >> 16) & 0xFF) / 255.0f;
		b = static_cast<float>((hex >> 8) & 0xFF) / 255.0f;
		a = static_cast<float>(hex & 0xFF) / 255.0f;
	}
}
