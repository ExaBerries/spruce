#pragma once
#include <spruce.h>
#include <scene/Scene.h>

using namespace spruce;

namespace sprucetest {
	class Cube : public Scene {
		public:
			aowner<Camera> camera;
			aowner<Mesh> cube;
			aowner<Mesh> plane;
			aowner<Mesh> screenQuad;
			float angle;

			Cube();
			~Cube();

			void load(RendererAbstractor* renderer) override;
			void update(float delta) override;
			owner<RendererAbstractor> getRenderer(SpruceTest& app, app::API api) override;
	};
}
