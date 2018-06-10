#pragma once
#include <common.h>
#include <graphics/command/Command.h>

namespace spruce {
	class CommandBuffer {
		public:
			std::vector<Command*> commands;

			CommandBuffer();
			virtual ~CommandBuffer();

			void add(Command* command);
			void reset();
	};
}
