#include <app.h>
#include <backend/api/RenderAPI.h>
#include <graphics/command/render/RenderPassCommand.h>

namespace spruce {
	RenderPassCommand::RenderPassCommand(graphics::RenderPass* renderPass) {
		this->renderPass = renderPass;
	}

	RenderPassCommand::~RenderPassCommand() {
	}

	void RenderPassCommand::execute() {
		app::api->renderStart(renderPass);
	}

	string RenderPassCommand::getName() const {
		return "RenderPass";
	}
}
