#pragma once
#include <common.h>
#include <app/API.h>

namespace spruce {
	class FramePipeline;

	class SpruceEngineHandle {
		public:
			SpruceEngineHandle();
			virtual ~SpruceEngineHandle();

			void setPipeline(FramePipeline* pipeline);
			void setRenderPipeline(app::API api);
	};
}
