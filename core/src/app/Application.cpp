#include <app/Application.h>

namespace spruce {
	Application::Application(SpruceEngineHandle& handle) : handle(handle) {
	}

	Application::~Application() {
	}

	void Application::setPipeline(FramePipeline* pipeline) {
		handle.setPipeline(pipeline);
	}

	void Application::setRenderAPI(app::API api) {
		handle.setRenderPipeline(api);
	}
}
