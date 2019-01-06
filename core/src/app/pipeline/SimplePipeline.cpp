#include <app/pipeline/SimplePipeline.h>
#include <task/async.h>
#include <app/pipeline/encode.h>

namespace spruce {
	SimplePipeline::SimplePipeline() {
		frame = nullptr;
	}

	SimplePipeline::~SimplePipeline() {
		if (frame != nullptr) {
			delete frame;
		}
	}

	void SimplePipeline::execute(float delta, Application& app, graphics::RendererAbstractor* renderer, ApplicationBackend& appBackend) {
		frame = new Frame();
		encodeFrame(*frame, delta, app, renderer);
		if (renderer != nullptr) {
			renderer->executeBackend(frame->rendererData);
		}
		delete frame;
		frame = nullptr;
		waitForMainTasks();
		appBackend.update();
	}
}
