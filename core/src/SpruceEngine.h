#pragma once
#include <types.h>
#include <app/API.h>
#include <app/ApplicationFwd.h>
#include <app/pipeline/FramePipeline.h>
#include <backend/Window.h>
#include <backend/ApplicationBackend.h>
#include <graphics/renderer/RendererAbstractor.h>
#include <graphics/renderer/api/APIContext.h>

namespace spruce {
	class SpruceEngine {
		public:
			owner<Application> application;
			owner<ApplicationBackend> appBackend;
			owner<FramePipeline> framePipeline;
			owner<Window> window;
			app::API apiType;
			APIContext* apiContext;
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
