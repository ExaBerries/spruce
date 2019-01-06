#pragma once
#include <common.h>
#include <app/API.h>
#include <SpruceEngine.h>
#include <app/pipeline/FramePipelineFwd.h>
#include <graphics/renderer/RendererAbstractorFwd.h>

namespace spruce {
	class Application {
		public:
			SpruceEngine& engine;

			Application(SpruceEngine& engine);
			virtual ~Application();

			virtual void update(float delta) = 0;
			virtual void* getRenderEncodeData();

			void setFramePipeline(FramePipeline* pipeline);
			void setRenderAPI(app::API api);
			bool supportsAPI(app::API api);
			void setRenderer(RendererAbstractor* renderer);
			RendererAbstractor* getRenderer();
			Window* getWindow();
	};
}
