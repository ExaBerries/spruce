#include <app/pipeline/EncodeExecutePipeline.h>
#include <app/app.h>
#include <graphics/graphics.h>
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

	void EncodeExecutePipeline::execute(Application& app) {
		executeFrame = encodeFrame;
		encodeFrame = new Frame();
		Task<void(Application&,float)> task = createTask<Application&,float>(std::function<void(Application&,float)>(spruce::encodeFrame), task::ENGINE, true, app, graphics::delta);
		#ifdef DEBUG
		#ifdef PROFILE
		uint64 startTime = sys::timeNano();
		#endif
		#endif
		os::updateStart();
		app::window->surface->renderStart();
		app::api->renderStart();
		std::vector<CommandBuffer>& commandBuffers = executeFrame->commandBuffers;
		for (CommandBuffer& cmdBuffer : commandBuffers) {
			for (cmd::Command* command : cmdBuffer.commands) {
				command->execute();
			}
		}
		#ifdef DEBUG
		#ifdef PROFILE
		uint64 endTime = sys::timeNano();
		execute->executeStartTime = startTime;
		execute->executeEndTime = endTime;
		#endif
		#endif
		delete executeFrame;
		executeFrame = nullptr;
		waitForMainTasks();
		app::api->renderEnd();
		app::window->surface->renderEnd();
		os::updateEnd();
	}

	void EncodeExecutePipeline::clearCommands() {
		if (encodeFrame != nullptr) {
			for (auto& cmdBuffer : encodeFrame->commandBuffers) {
				cmdBuffer.reset();
			}
		}
		if (executeFrame != nullptr) {
			for (auto& cmdBuffer : executeFrame->commandBuffers) {
				cmdBuffer.reset();
			}
		}
	}

	CommandBuffer& EncodeExecutePipeline::getCommandBuffer() {
		return encodeFrame->getCommandBuffer();
	}
}
