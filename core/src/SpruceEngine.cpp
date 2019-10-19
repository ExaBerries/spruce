#include <SpruceEngine.h>
#include <app/Application.h>
#include <backend/os.h>
#include <backend/task/taskmanager.h>

namespace spruce {
	SpruceEngine::SpruceEngine(owner<Application> (*createApplication)(SpruceEngine&)) {
		framePipeline = nullptr;
		apiType = app::DEBUG_API;
		renderer = nullptr;
		apiContext = nullptr;
		os::init();
		task::init();
		appBackend = os::createAppBackend();
		window = appBackend->createWindow();
		application = createApplication(*this);
	}

	SpruceEngine::~SpruceEngine() {
		if (window->open) {
			window->close();
		}
		delete application;
		delete apiContext;
		delete window;
		delete framePipeline;
		task::free();
		os::free();
	}

	void SpruceEngine::run() {
		int64 lastTime = sys::timeNano();
		while (window->open) {
			float delta = static_cast<float>(sys::timeNano() - lastTime) / 1.0e9f;
			lastTime = sys::timeNano();
			if (application != nullptr) {
				framePipeline->execute(delta, *application, renderer, *appBackend);
			}
		}
	}

	void SpruceEngine::setRenderAPI(app::API newAPI) {
		this->apiType = newAPI;
		if (apiContext != nullptr) {
			delete apiContext;
		}
		apiContext = window->initAPI(newAPI);
	}

	void SpruceEngine::setFramePipeline(owner<FramePipeline> pipeline) {
		if (this->framePipeline != nullptr) {
			delete this->framePipeline;
		}
		this->framePipeline = pipeline;
	}

	void SpruceEngine::setRenderer(owner<RendererAbstractor> renderer) {
		if (this->renderer != nullptr) {
			delete this->renderer;
		}
		this->renderer = renderer;
	}

	bool SpruceEngine::supportsAPI(app::API api) {
		return appBackend->supportsAPI(api);
	}

	const buffer<app::API> SpruceEngine::getSupportedAPIs() {
		return appBackend->supportedAPIs;
	}
}
