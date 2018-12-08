#pragma once
#include <common.h>
#include <app/Application.h>
#include <app/API.h>
#include <backend/Window.h>
#include <backend/api/RenderAPI.h>
#include <app/pipeline/SimplePipeline.h>
#include <app/pipeline/EncodeExecutePipeline.h>
#include <app/pipeline/FramePipeline.h>

namespace spruce {
	namespace app {
		extern std::vector<std::function<void()>> freeCallbacks;
		extern Window* window;
		extern API apiType;
		extern RenderAPI* api;
		extern bool debug;
		extern FramePipeline* pipeline;

		void init(Application& app);
		void run(Application& app);
		void free(Application& app);

		void setPipeline(FramePipeline* pipeline);
		bool supportsAPI(API api);
		void setRenderAPI(API api);
		void clearCommands();
		void addFreeCallback(std::function<void()> function);
	}
}
