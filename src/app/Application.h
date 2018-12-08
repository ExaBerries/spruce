#pragma once
#include <common.h>

namespace spruce {
	class Application {
		public:
			Application();
			virtual ~Application();

			virtual void init() = 0;
			virtual void free() = 0;
			virtual void render(float delta) = 0;
			virtual void update(float delta) = 0;
	};
}
