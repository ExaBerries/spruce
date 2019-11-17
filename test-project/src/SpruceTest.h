#pragma once
#include <spruce.h>
#include <scene/Scene.h>

using namespace spruce;

namespace sprucetest {
	class SpruceTest : public Application, input::InputProcessor {
		public:
			enum SCENE {
				BASIC, CUBE, BENCH
			};
			SCENE sceneType;
			owner<Scene> scene;
			bool swapAPI;
			bool swapScene;
			owner<Font> font;

			SpruceTest(SpruceEngine& engine);
			~SpruceTest();

			void update(float delta) noexcept;
			void* getRenderEncodeData() noexcept;

			void keyDown(uint16 code) noexcept;
			void keyUp(uint16 code) noexcept;
			void mouseDown(input::MouseButton button) noexcept;
			void mouseUp(input::MouseButton button) noexcept;
			void mouseMove(vec2f newPos) noexcept;
	};
}
