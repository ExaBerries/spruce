#include <graphics/command/mesh/MeshBindCommand.h>
#include <app/app.h>

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
