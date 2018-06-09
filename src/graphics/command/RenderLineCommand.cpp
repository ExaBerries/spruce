#include <graphics/command/RenderLineCommand.h>
#include <app.h>
#include <backend/api/RenderAPI.h>

namespace spruce {
	RenderLineCommand::RenderLineCommand(vec3f a, vec3f b, color cola, color colb) : a(a), b(b), cola(cola), colb(colb) {
	}

	RenderLineCommand::~RenderLineCommand() {
	}

	void RenderLineCommand::execute() {
		app::api->renderLine(a, b, cola, colb);
	}

	string RenderLineCommand::getName() {
		return "RenderLine";
	}
}
