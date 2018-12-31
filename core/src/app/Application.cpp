#include <app/Application.h>

namespace spruce {
	Application::Application(SpruceEngine& engine) : engine(engine) {
	}

	Application::~Application() {
	}

	void Application::setFramePipeline(FramePipeline* pipeline) {
		engine.setFramePipeline(pipeline);
	}

	void Application::setRenderAPI(app::API api) {
		engine.setRenderAPI(api);
	}

	bool Application::supportsAPI(app::API api) {
		return engine.supportsAPI(api);
	}

	void Application::setRenderer(RendererAbstractor* renderer) {
		engine.setRenderer(renderer);
	}
}
