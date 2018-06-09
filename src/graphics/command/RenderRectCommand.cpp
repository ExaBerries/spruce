#include <graphics/command/RenderRectCommand.h>
#include <app.h>
#include <backend/api/RenderAPI.h>

namespace spruce {
	RenderRectCommand::RenderRectCommand(vec2f pos, vec2f size, spruce::color color) : pos(pos), size(size), color(color) {
	}

	RenderRectCommand::~RenderRectCommand() {
	}

	void RenderRectCommand::execute() {
		app::api->renderRect(pos, size, color);
	}

	string RenderRectCommand::getName() {
		return "RenderRect";
	}
}
