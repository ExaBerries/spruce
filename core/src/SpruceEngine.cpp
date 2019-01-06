#include <SpruceEngine.h>
#include <app/Application.h>
#include <backend/os.h>
#include <backend/task/taskmanager.h>

namespace spruce {
	SpruceEngine::SpruceEngine(Application* (*createApplication)(SpruceEngine&)) {
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
		delete window;
		delete framePipeline;
		task::free();
		os::free();
		delete application;
	}

	void SpruceEngine::run() {
		uint64 lastTime = sys::timeNano();
		while (window->open) {
			float delta = ((float)(sys::timeNano() - lastTime) / 1.0e9);
			lastTime = sys::timeNano();
			if (application != nullptr) {
				framePipeline->execute(delta, *application, renderer, *appBackend);
			}
		}
	}

	void SpruceEngine::setRenderAPI(app::API newAPI) {
		this->apiType = newAPI;
		apiContext = window->initAPI(app::OPENGL);
	}

	void SpruceEngine::setFramePipeline(FramePipeline* pipeline) {
		this->framePipeline = pipeline;
	}

	void SpruceEngine::setRenderer(RendererAbstractor* renderer) {
		if (this->renderer != nullptr) {
			delete renderer;
		}
		this->renderer = renderer;
	}

	bool SpruceEngine::supportsAPI(app::API api) {
		return appBackend->supportsAPI(api);
	}
}
