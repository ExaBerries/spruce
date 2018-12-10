#include <graphics/command/render/RenderFontCommand.h>
#include <app/app.h>

namespace spruce {
	namespace graphics {
		namespace cmd {
			RenderFontCommand::RenderFontCommand(string str, Font& font, spruce::color color, vec3f position, quaternion rotation, vec2f size, mat4f camera) : font(font) {
				this->str = str;
				this->color = color;
				this->position = position;
				this->rotation = rotation;
				this->size = size;
				this->camera = camera;
			}

			RenderFontCommand::~RenderFontCommand() {
			}

			void RenderFontCommand::execute() {
				app::api->render(str, font, color, position, rotation, size, camera);
			}

			string RenderFontCommand::getName() const {
				return "RenderFont";
			}
		}
	}
}
