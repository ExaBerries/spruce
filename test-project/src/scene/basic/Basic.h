#pragma once
#include <spruce.h>
#include <scene/Scene.h>

using namespace spruce;

namespace sprucetest {
	class Basic : public Scene {
		public:
			aowner<PerspectiveCamera> camera;
			aowner<Mesh> cubeMesh;
			float angle;

			Basic();
			~Basic();

			void load(RendererAbstractor* renderer) override;
			void update(float delta) override;
			owner<RendererAbstractor> getRenderer(SpruceTest& app, app::API api) override;
	};
}
