#include <app/pipeline/encode.h>
#include <app/app.h>
#include <task/async.h>

namespace spruce {
	void encodeFrame(Application& app, float delta) {
		#ifdef DEBUG
		#ifdef PROFILE
		uint64 startTime = sys::timeNano();
		#endif
		#endif
		app.update(delta);
		app.render(delta);
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
