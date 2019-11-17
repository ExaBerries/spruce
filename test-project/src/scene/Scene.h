#pragma once
#include <spruce.h>

using namespace spruce;

namespace sprucetest {
	class SpruceTest; // TODO: proper forwards declaration

	class Scene {
		public:
			vec2i windowSize;

			Scene() = default;
			virtual ~Scene() = default;

			virtual void load(RendererAbstractor* renderer) = 0;
			virtual void update(float delta) = 0;
			virtual owner<RendererAbstractor> getRenderer(SpruceTest& app, app::API api) = 0;
	};
}
