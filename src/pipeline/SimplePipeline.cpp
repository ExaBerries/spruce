#include <pipeline/SimplePipeline.h>
#include <app.h>
#include <backend/os.h>
#include <graphics/graphics.h>
#include <task/async.h>
#include <pipeline/encode.h>

namespace spruce {
	SimplePipeline::SimplePipeline() {
		frame = nullptr;
	}

	SimplePipeline::~SimplePipeline() {
		if (frame != nullptr) {
			delete frame;
		}
	}

	void SimplePipeline::execute() {
		frame = new Frame();
		if (app::screen != nullptr) {
			encodeFrame(graphics::delta);
		}
		#ifdef DEBUG
		#ifdef PROFILE
		uint64 startTime = sys::timeNano();
		#endif
		#endif
		os::updateStart();
		app::window->surface->renderStart();
		app::api->renderStart();
		buffer<CommandBuffer*> commandBuffers = frame->getCommandBuffers();
		for (CommandBuffer* cmdBuffer : commandBuffers) {
			for (cmd::Command* command : cmdBuffer->commands) {
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
		commandBuffers.free();
		delete frame;
		frame = nullptr;
		waitForMainTasks();
		app::api->renderEnd();
		app::window->surface->renderEnd();
		os::updateEnd();
	}

	void SimplePipeline::clearCommands() {
		if (frame != nullptr) {
			for (auto& entry : frame->commandBuffers) {
				entry.second.reset();
			}
		}
	}

	CommandBuffer& SimplePipeline::getCommandBuffer() {
		return frame->getCommandBuffer();
	}
}
