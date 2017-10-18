#pragma once
#include <common.h>

namespace spruce {
	struct color {
		public:
			float r;
			float g;
			float b;
			float a;

			color();
			color(float r, float g, float b, float a);
			color(int32 hex);
			virtual ~color();
	};
}
