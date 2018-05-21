#include <graphics/command/RenderMeshCommand.h>
#include <app.h>
#include <backend/api/RenderAPI.h>

namespace spruce {
	RenderMeshCommand::RenderMeshCommand(Mesh* mesh, Shader* shader) {
		this->mesh = mesh;
		this->shader = shader;
	}

	RenderMeshCommand::~RenderMeshCommand() {
	}

	void RenderMeshCommand::execute() {
		app::api->render(mesh, shader);
	}

	string RenderMeshCommand::getName() {
		return "RenderMesh";
	}
}
