#pragma once

namespace spruce {
	namespace graphics {
		class Screen {
			public:
				Screen();
				virtual ~Screen();

				void render(float delta);
		};
	}
}
