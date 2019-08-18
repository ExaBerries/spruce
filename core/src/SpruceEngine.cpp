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
		delete (Window*)window;
		delete (FramePipeline*)framePipeline;
		task::free();
		os::free();
		delete (Application*)application;
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
		if (apiContext != nullptr) {
			delete apiContext;
		}
		apiContext = window->initAPI(app::OPENGL);
	}

	void SpruceEngine::setFramePipeline(FramePipeline* pipeline) {
		if (this->framePipeline != nullptr) {
			delete (FramePipeline*)this->framePipeline;
		}
		this->framePipeline = pipeline;
	}

	void SpruceEngine::setRenderer(RendererAbstractor* renderer) {
		if (this->renderer != nullptr) {
			delete this->renderer;
		}
		this->renderer = renderer;
	}

	bool SpruceEngine::supportsAPI(app::API api) {
		return appBackend->supportsAPI(api);
	}
}
