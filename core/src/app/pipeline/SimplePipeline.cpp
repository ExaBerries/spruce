#include <app/pipeline/SimplePipeline.h>
#include <task/async.h>
#include <app/pipeline/encode.h>

namespace spruce {
	void SimplePipeline::execute(float delta, Application& app, graphics::RendererAbstractor* renderer, ApplicationBackend& appBackend) noexcept {
		frame.cons();
		encodeFrame(*frame, delta, app, renderer);
		if (renderer != nullptr) {
			renderer->executeBackend(frame->rendererData);
		}
		frame.desc();
		waitForMainTasks();
		appBackend.update();
	}
}
