#include <Frame.h>
#include <backend/task/taskmanager.h>

namespace spruce {
	Frame::Frame() {
	}

	Frame::Frame(const Frame& frame) {
		this->mainCommandBuffer = frame.mainCommandBuffer;
		this->commandBuffers = frame.commandBuffers;
	}

	Frame::~Frame() {
		mainCommandBuffer.reset();
		for (auto& cmdBuffer : commandBuffers) {
			cmdBuffer.second.reset();
		}
	}

	CommandBuffer& Frame::getCommandBuffer() {
		for (auto& cmdBuffer : commandBuffers) {
			if (cmdBuffer.first == std::this_thread::get_id()) {
				return cmdBuffer.second;
			}
		}
		return mainCommandBuffer;
	}

	buffer<CommandBuffer*> Frame::getCommandBuffers() {
		buffer<CommandBuffer*> cmdBuffers(commandBuffers.size() + 1);
		uint16 i = 0;
		cmdBuffers[i++] = &mainCommandBuffer;
		for (auto& cmdBuffer : commandBuffers) {
			cmdBuffers[i++] = &cmdBuffer.second;
		}
		return cmdBuffers;
	}

	Frame& Frame::operator=(Frame frame) {
		this->mainCommandBuffer = frame.mainCommandBuffer;
		this->commandBuffers = frame.commandBuffers;
		return *this;
	}
}
