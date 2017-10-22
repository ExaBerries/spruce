#pragma once
#include <common.h>

namespace spruce {
	struct color {
		float r;
		float g;
		float b;
		float a;

		color();
		color(float r, float g, float b, float a);
		color(int32 hex);
		virtual ~color();

		friend std::ostream& operator<<(std::ostream& stream, const color& color);
	};
}
