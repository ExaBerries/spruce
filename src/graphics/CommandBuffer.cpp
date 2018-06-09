#include <graphics/CommandBuffer.h>

namespace spruce {
	CommandBuffer::CommandBuffer() {
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
}
