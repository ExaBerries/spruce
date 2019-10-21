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
			Application(const Application&) = delete;
			Application(Application&&) noexcept = delete;
			virtual ~Application() = default;

			virtual void update(float delta) noexcept = 0;
			virtual void* getRenderEncodeData() noexcept;

			void setFramePipeline(owner<FramePipeline> pipeline) noexcept;
			void setRenderAPI(app::API api) noexcept;
			[[nodiscard]] bool supportsAPI(app::API api) const noexcept;
			[[nodiscard]] const buffer<app::API>& getSupportedAPIs() const noexcept;
			void setRenderer(owner<RendererAbstractor> renderer) noexcept;
			[[nodiscard]] RendererAbstractor* getRenderer() noexcept;
			[[nodiscard]] Window* getWindow() noexcept;

			Application& operator=(const Application&) = delete;
			Application& operator=(Application&&) noexcept = delete;
	};
}
