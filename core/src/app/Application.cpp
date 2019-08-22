#include <app/Application.h>

namespace spruce {
	Application::Application(SpruceEngine& engine) : engine(engine) {
	}

	Application::~Application() {
	}

	void* Application::getRenderEncodeData() {
		return this;
	}

	void Application::setFramePipeline(FramePipeline* pipeline) {
		engine.setFramePipeline(pipeline);
	}

	void Application::setRenderAPI(app::API api) {
		engine.setRenderAPI(api);
	}

	bool Application::supportsAPI(app::API api) const {
		return engine.supportsAPI(api);
	}

	const buffer<app::API> Application::getSupportedAPIs() const {
		return engine.getSupportedAPIs();
	}

	void Application::setRenderer(RendererAbstractor* renderer) {
		engine.setRenderer(renderer);
	}

	RendererAbstractor* Application::getRenderer() {
		return engine.renderer;
	}

	Window* Application::getWindow() {
		return engine.window;
	}
}
