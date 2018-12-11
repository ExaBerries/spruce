#include <SpruceEngineHandle.h>
#include <app/app.h>

namespace spruce {
	SpruceEngineHandle::SpruceEngineHandle() {
	}

	SpruceEngineHandle::~SpruceEngineHandle() {
	}

	void SpruceEngineHandle::setPipeline(FramePipeline* pipeline) {
		app::setPipeline(pipeline);
	}

	void SpruceEngineHandle::setRenderPipeline(app::API api) {
		app::setRenderAPI(api);
	}
}
