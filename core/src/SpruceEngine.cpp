#include <SpruceEngine.h>
#include <app/app.h>

namespace spruce {
	SpruceEngine::SpruceEngine(Application* (*createApplication)(SpruceEngineHandle&)) {
		pipeline = nullptr;
		window = nullptr;
		apiType = app::OPENGL;
		api = nullptr;
		debug = true;
		app::init();
		SpruceEngineHandle handle;
		application = createApplication(handle);
	}

	SpruceEngine::~SpruceEngine() {
		app::free();
		delete application;
	}

	void SpruceEngine::run() {
		app::run(*application);
	}
}
