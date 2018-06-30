#include <graphics/CommandBuffer.h>

namespace spruce {
	CommandBuffer::CommandBuffer() {
		locked = false;
	}

	CommandBuffer::CommandBuffer(const CommandBuffer& cmdBuffer) {
		this->locked = cmdBuffer.locked;
		this->commands = cmdBuffer.commands;
	}

	CommandBuffer::~CommandBuffer() {
	}

	void CommandBuffer::add(Command* command) {
		while (locked);
		commands.push_back(command);
	}

	void CommandBuffer::reset() {
		locked = true;
		for (Command* cmd : commands) {
			delete cmd;
		}
		commands.clear();
		locked = false;
	}

	CommandBuffer& CommandBuffer::operator=(CommandBuffer cmdBuffer) {
		this->commands = cmdBuffer.commands;
		return *this;
	}
}
