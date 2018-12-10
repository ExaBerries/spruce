#include <graphics/command/render/RenderMeshCommand.h>
#include <app/app.h>

namespace spruce {
	namespace graphics {
		namespace cmd {
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

			string RenderMeshCommand::getName() const {
				return "RenderMesh";
			}
		}
	}
}
