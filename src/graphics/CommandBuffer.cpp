#include <graphics/CommandBuffer.h>

namespace spruce {
	CommandBuffer::CommandBuffer() {
	}

	CommandBuffer::CommandBuffer(const CommandBuffer& cmdBuffer) {
		this->commands = cmdBuffer.commands;
	}

	CommandBuffer::~CommandBuffer() {
	}

	void CommandBuffer::add(Command* command) {
		commands.push_back(command);
	}

	void CommandBuffer::reset() {
		for (Command* cmd : commands) {
			delete cmd;
		}
		commands.clear();
	}

	CommandBuffer& CommandBuffer::operator=(CommandBuffer cmdBuffer) {
		this->commands = cmdBuffer.commands;
		return *this;
	}
}
