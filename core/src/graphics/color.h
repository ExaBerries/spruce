#pragma once
#include <common.h>

namespace spruce {
	struct color {
		float r;
		float g;
		float b;
		float a;

		color();
		color(const color& color);
		color(float r, float g, float b, float a);
		color(int32 hex);
		~color();

		bool operator==(const color& color) const;
		bool operator!=(const color& color) const;

		friend std::ostream& operator<<(std::ostream& stream, const color& color);
	};
}
