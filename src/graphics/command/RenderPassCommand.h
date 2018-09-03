#pragma once
#include <common.h>
#include <graphics/command/Command.h>
#include <graphics/RenderPass.h>

namespace spruce {
	class RenderPassCommand : public Command {
		public:
			graphics::RenderPass* renderPass;

			RenderPassCommand(graphics::RenderPass* renderPass);
			virtual ~RenderPassCommand();

			void execute();
			string getName() const;
	};
}
