#pragma once
#include <common.h>
#include <SpruceEngineHandle.h>

namespace spruce {
	class Application {
		public:
			SpruceEngineHandle handle;

			Application(SpruceEngineHandle& handle);
			virtual ~Application();

			virtual void render(float delta) = 0;
			virtual void update(float delta) = 0;

			void setPipeline(FramePipeline* pipeline);
			void setRenderAPI(app::API api);
	};
}
