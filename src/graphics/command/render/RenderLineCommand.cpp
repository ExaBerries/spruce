#include <graphics/command/render/RenderLineCommand.h>
#include <app.h>

namespace spruce {
	namespace graphics {
		namespace cmd {
			RenderLineCommand::RenderLineCommand(vec3f a, vec3f b, color cola, color colb, mat4f camera) : a(a), b(b), cola(cola), colb(colb), camera(camera) {
			}

			RenderLineCommand::~RenderLineCommand() {
			}

			void RenderLineCommand::execute() {
				app::api->renderLine(a, b, cola, colb, camera);
			}

			string RenderLineCommand::getName() const {
				return "RenderLine";
			}
		}
	}
}
