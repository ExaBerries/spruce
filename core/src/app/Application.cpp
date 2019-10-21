#include <app/Application.h>

namespace spruce {
	Application::Application(SpruceEngine& engine) : engine(engine) {
	}

	void* Application::getRenderEncodeData() noexcept {
		return this;
	}

	void Application::setFramePipeline(owner<FramePipeline> pipeline) noexcept {
		engine.setFramePipeline(pipeline);
	}

	void Application::setRenderAPI(app::API api) noexcept {
		engine.setRenderAPI(api);
	}

	bool Application::supportsAPI(app::API api) const noexcept {
		return engine.supportsAPI(api);
	}

	const buffer<app::API>& Application::getSupportedAPIs() const noexcept {
		return engine.getSupportedAPIs();
	}

	void Application::setRenderer(owner<RendererAbstractor> renderer) noexcept {
		engine.setRenderer(renderer);
	}

	RendererAbstractor* Application::getRenderer() noexcept {
		return engine.renderer;
	}

	Window* Application::getWindow() noexcept {
		return engine.window;
	}
}
