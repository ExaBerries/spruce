#pragma once
#include <common.h>

namespace spruce {
	namespace graphics {
		class Screen {
			public:
				Screen();
				Screen(const Screen& screen);
				virtual ~Screen();

				virtual void render(float delta) = 0;
				virtual void update(float delta) = 0;
		};
	}
}
