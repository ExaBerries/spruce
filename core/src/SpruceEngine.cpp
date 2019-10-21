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

	void SpruceEngine::run() noexcept {
		int64 lastTime = sys::timeNano();
		while (window->open) {
			float delta = static_cast<float>(sys::timeNano() - lastTime) / 1.0e9f;
			lastTime = sys::timeNano();
			if (application != nullptr) {
				framePipeline->execute(delta, *application, renderer, *appBackend);
			}
		}
	}

	void SpruceEngine::setRenderAPI(app::API newAPI) noexcept {
		this->apiType = newAPI;
		delete apiContext;
		apiContext = window->initAPI(newAPI);
	}

	void SpruceEngine::setFramePipeline(owner<FramePipeline> pipeline) noexcept {
		delete this->framePipeline;
		this->framePipeline = pipeline;
	}

	void SpruceEngine::setRenderer(owner<RendererAbstractor> renderer) noexcept {
		delete this->renderer;
		this->renderer = renderer;
	}

	bool SpruceEngine::supportsAPI(app::API api) noexcept {
		return appBackend->supportsAPI(api);
	}

	const buffer<app::API>& SpruceEngine::getSupportedAPIs() noexcept {
		return appBackend->supportedAPIs;
	}
}
