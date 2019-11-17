#pragma once
#include <scene/Scene.h>
#include <spruce.h>

using namespace spruce;

namespace sprucetest {
	class Bench : public Scene {
		public:
			aowner<Camera> camera;
			aowner<Mesh> plane;
			float angle;

			Bench();
			~Bench();

			void load(RendererAbstractor* renderer) override;
			void update(float delta) override;
			owner<RendererAbstractor> getRenderer(SpruceTest& app, app::API api) override;
	};
}
