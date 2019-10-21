#include <app/pipeline/EncodeExecutePipeline.h>
#include <task/async.h>
#include <app/pipeline/encode.h>

namespace spruce {
	EncodeExecutePipeline::EncodeExecutePipeline() {
		encodeFrame.cons();
	}

	void EncodeExecutePipeline::execute(float delta, Application& app, graphics::RendererAbstractor* renderer, ApplicationBackend& appBackend) noexcept{
		executeFrame = std::move(encodeFrame);
		encodeFrame.cons();
		Task<void(Frame&,float,Application&,RendererAbstractor*)> task = createTask<Frame&,float,Application&,RendererAbstractor*>(std::function<void(Frame&,float,Application&,RendererAbstractor*)>(spruce::encodeFrame), task::ENGINE, true, *encodeFrame, delta, app, renderer);
		if (renderer != nullptr) {
			renderer->executeBackend(executeFrame->rendererData);
		}
		executeFrame.desc();
		waitForMainTasks();
		appBackend.update();
	}
}
