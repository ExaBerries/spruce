#include <graphics/command/ShaderBindCommand.h>
#include <app.h>
#include <backend/api/RenderAPI.h>

namespace spruce {
	ShaderBindCommand::ShaderBindCommand(Shader* shader) {
		this->shader = shader;
	}

	ShaderBindCommand::~ShaderBindCommand() {
	}

	void ShaderBindCommand::execute() {
		app::api->bind(shader);
	}

	string ShaderBindCommand::getName() const {
		return "ShaderBind";
	}
}
