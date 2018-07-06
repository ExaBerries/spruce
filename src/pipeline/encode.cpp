#include <pipeline/encode.h>
#include <app.h>
#include <task/async.h>

namespace spruce {
	void encodeFrame(float delta) {
		#ifdef DEBUG
		#ifdef PROFILE
		uint64 startTime = sys::timeNano();
		#endif
		#endif
		app::screen->update(delta);
		app::screen->render(delta);
		waitForGraphicsTasks(true);
		#ifdef DEBUG
		#ifdef PROFILE
		uint64 endTime = sys::timeNano();
		encode->encodeStartTime = startTime;
		encode->encodeEndTime = endTime;
		encode->delta = delta;
		#endif
		#endif
	}
}
