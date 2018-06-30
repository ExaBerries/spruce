#pragma once
#include <common.h>
#include <graphics/command/Command.h>

namespace spruce {
	class CommandBuffer {
		public:
			std::vector<Command*> commands;
			bool locked;

			CommandBuffer();
			CommandBuffer(const CommandBuffer& cmdBuffer);
			virtual ~CommandBuffer();

			void add(Command* command);
			void reset();

			CommandBuffer& operator=(CommandBuffer cmdBuffer);
	};
}
