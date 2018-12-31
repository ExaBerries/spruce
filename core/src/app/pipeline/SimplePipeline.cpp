#include <app/pipeline/SimplePipeline.h>
#include <backend/os.h>
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

	void SimplePipeline::execute(float delta, Application& app, graphics::RendererAbstractor* renderer) {
		frame = new Frame();
		encodeFrame(*frame, delta, app, renderer);
		os::updateStart();
		//app::window->surface->renderStart();
		//app::api->renderStart();
		if (renderer != nullptr) {
			renderer->executeBackend(frame->rendererData);
		}
		delete frame;
		frame = nullptr;
		waitForMainTasks();
		//app::api->renderEnd();
		//app::window->surface->renderEnd();
		os::updateEnd();
	}
}
