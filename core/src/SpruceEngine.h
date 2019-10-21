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
			owner<APIContext> apiContext;
			owner<RendererAbstractor> renderer;

			explicit SpruceEngine(owner<Application> (*createApplication)(SpruceEngine&));
			SpruceEngine(const SpruceEngine&) = delete;
			SpruceEngine(SpruceEngine&&) noexcept = delete;
			~SpruceEngine();

			void run() noexcept;
			void setRenderAPI(app::API newAPI) noexcept;
			void setFramePipeline(owner<FramePipeline> pipeline) noexcept;
			void setRenderer(owner<RendererAbstractor> renderer) noexcept;
			bool supportsAPI(app::API api) noexcept;
			const buffer<app::API>& getSupportedAPIs() noexcept;

			SpruceEngine& operator=(const SpruceEngine&) = delete;
			SpruceEngine& operator=(SpruceEngine&&) noexcept = delete;
	};
}
