#include <graphics/command/render/RenderPassCommand.h>
#include <app.h>

namespace spruce {
	namespace graphics {
		namespace cmd {
			RenderPassCommand::RenderPassCommand(graphics::RenderPass* renderPass) {
				this->renderPass = renderPass;
			}

			RenderPassCommand::~RenderPassCommand() {
			}

			void RenderPassCommand::execute() {
				app::api->changeTarget(renderPass->target);
			}

			string RenderPassCommand::getName() const {
				return "RenderPass";
			}
		}
	}
}
