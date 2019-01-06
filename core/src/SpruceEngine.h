#pragma once
#include <types.h>
#include <app/ApplicationFwd.h>
#include <app/pipeline/FramePipeline.h>
#include <backend/Window.h>
#include <app/API.h>
#include <graphics/renderer/RendererAbstractor.h>
#include <backend/ApplicationBackend.h>

namespace spruce {
	class SpruceEngine {
		public:
			Application* application;
			ApplicationBackend* appBackend;
			FramePipeline* framePipeline;
			Window* window;
			app::API apiType;
			void* apiContext;
			RendererAbstractor* renderer;

			explicit SpruceEngine(Application* (*createApplication)(SpruceEngine&));
			SpruceEngine(const SpruceEngine&) = delete;
			SpruceEngine(SpruceEngine&&) noexcept = delete;
			~SpruceEngine();

			void run();
			void setRenderAPI(app::API newAPI);
			void setFramePipeline(FramePipeline* pipeline);
			void setRenderer(RendererAbstractor* renderer);
			bool supportsAPI(app::API api);

			SpruceEngine& operator=(const SpruceEngine&) = delete;
			SpruceEngine& operator=(SpruceEngine&&) noexcept = delete;
	};
}
