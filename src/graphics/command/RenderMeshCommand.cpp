#include <graphics/command/RenderMeshCommand.h>
#include <app.h>
#include <backend/api/RenderAPI.h>

namespace spruce {
	RenderMeshCommand::RenderMeshCommand(Mesh* mesh, Shader* shader, graphics::Primitive primitive) {
		this->mesh = mesh;
		this->shader = shader;
		this->primitive = primitive;
	}

	RenderMeshCommand::~RenderMeshCommand() {
	}

	void RenderMeshCommand::execute() {
		app::api->render(mesh, shader, primitive);
	}

	string RenderMeshCommand::getName() {
		return "RenderMesh";
	}
}
