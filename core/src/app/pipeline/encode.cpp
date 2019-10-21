#include <app/pipeline/encode.h>
#include <task/async.h>

namespace spruce {
	void encodeFrame(Frame& frame, float delta, Application& app, RendererAbstractor* renderer) noexcept {
		app.update(delta);
		if (renderer != nullptr) {
			frame.rendererData = renderer->encodeBackend(app.getRenderEncodeData());
		}
		waitForGraphicsTasks(true);
	}
}
