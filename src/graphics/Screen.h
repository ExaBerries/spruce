#pragma once
#include <common.h>

namespace spruce {
	namespace graphics {
		class Screen {
			public:
				virtual void render(float delta) = 0;
				virtual void update(float delta) = 0;
		};
	}
}
