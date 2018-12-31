#include <app/pipeline/EncodeExecutePipeline.h>
#include <task/async.h>
#include <backend/os.h>
#include <app/pipeline/encode.h>

namespace spruce {
	EncodeExecutePipeline::EncodeExecutePipeline() {
		encodeFrame = new Frame();
		executeFrame = nullptr;
	}

	EncodeExecutePipeline::~EncodeExecutePipeline() {
		if (encodeFrame != nullptr) {
			delete encodeFrame;
		}
		if (executeFrame != nullptr) {
			delete executeFrame;
		}
	}

	void EncodeExecutePipeline::execute(float delta, Application& app, graphics::RendererAbstractor* renderer) {
		executeFrame = encodeFrame;
		encodeFrame = new Frame();
		Task<void(Frame&,float,Application&,RendererAbstractor*)> task = createTask<Frame&,float,Application&,RendererAbstractor*>(std::function<void(Frame&,float,Application&,RendererAbstractor*)>(spruce::encodeFrame), task::ENGINE, true, *encodeFrame, delta, app, renderer);
		os::updateStart();
		//app::window->surface->renderStart();
		//app::api->renderStart();
		if (renderer != nullptr) {
			renderer->executeBackend(executeFrame->rendererData);
		}
		delete executeFrame;
		executeFrame = nullptr;
		waitForMainTasks();
		//app::api->renderEnd();
		//app::window->surface->renderEnd();
		os::updateEnd();
	}
}
