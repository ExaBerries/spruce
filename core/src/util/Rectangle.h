#pragma once
#include <common.h>

namespace spruce {
	class Rectangle {
		public:
			vec2f size;

			Rectangle(vec2f size);
			virtual ~Rectangle();

			static bool overlap(const Rectangle& a, const vec2f& apos, const Rectangle& b, const vec2f& bpos);
	};
}
