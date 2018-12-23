#pragma once
#include <types.h>
#include <app/Application.h>
#include <app/pipeline/FramePipeline.h>
#include <backend/Window.h>
#include <app/API.h>
#include <backend/api/RenderAPI.h>

namespace spruce {
	class SpruceEngine {
		public:
			Application* application;
			FramePipeline* pipeline;
			Window* window;
			app::API apiType;
			RenderAPI* api;
			bool debug;

			SpruceEngine(Application* (*createApplication)(SpruceEngineHandle&));
			~SpruceEngine();

			void run();
	};
}
