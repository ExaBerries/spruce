#include <app/pipeline/encode.h>
#include <task/async.h>

namespace spruce {
	void encodeFrame(Frame& frame, float delta, Application& app, RendererAbstractor* renderer) {
		app.update(delta);
		if (renderer != nullptr) {
			frame.rendererData = renderer->encodeBackend(app);
		}
		waitForGraphicsTasks(true);
	}
}
