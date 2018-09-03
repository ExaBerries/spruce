#include <graphics/command/MeshBindCommand.h>
#include <app.h>
#include <backend/api/RenderAPI.h>

namespace spruce {
	MeshBindCommand::MeshBindCommand(Mesh* mesh) {
		this->mesh = mesh;
	}

	MeshBindCommand::~MeshBindCommand() {
	}

	void MeshBindCommand::execute() {
		app::api->bind(mesh);
	}

	string MeshBindCommand::getName() const {
		return "MeshBind";
	}
}
