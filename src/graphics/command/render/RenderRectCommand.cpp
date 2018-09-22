#include <app.h>
#include <backend/api/RenderAPI.h>
#include <graphics/command/render/RenderRectCommand.h>

namespace spruce {
	namespace graphics {
		namespace cmd {
			RenderRectCommand::RenderRectCommand(vec3f pos, vec2f size, spruce::color color, quaternion rotation, mat4f camera) : pos(pos), size(size), color(color), rotation(rotation), camera(camera) {
			}

			RenderRectCommand::~RenderRectCommand() {
			}

			void RenderRectCommand::execute() {
				app::api->renderRect(pos, size, color, rotation, camera);
			}

			string RenderRectCommand::getName() const {
				return "RenderRect";
			}
		}
	}
}
