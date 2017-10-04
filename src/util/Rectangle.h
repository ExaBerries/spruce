#pragma once
#include <common.h>
#include <math/vec2f.h>

namespace spruce {
	class Rectangle {
		public:
			vec2f size;

			Rectangle(vec2f size);
			virtual ~Rectangle();

			static bool overlap(Rectangle a, vec2f apos, Rectangle b, vec2f bpos);
	};
}
