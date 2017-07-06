#pragma once

namespace spruce {
	namespace graphics {
		class Screen {
			public:
				Screen();
				virtual ~Screen();

				virtual void render(float delta);
				virtual void update(float delta);
		};
	}
}
