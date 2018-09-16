#include <app.h>
#include <backend/api/RenderAPI.h>
#include <graphics/command/mesh/MeshBindCommand.h>

namespace spruce {
	namespace graphics {
		namespace cmd {
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
	}
}
