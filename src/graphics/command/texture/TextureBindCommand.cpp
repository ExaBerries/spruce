#include <app.h>
#include <backend/api/RenderAPI.h>
#include <graphics/command/texture/TextureBindCommand.h>

namespace spruce {
	namespace graphics {
		namespace cmd {
			TextureBindCommand::TextureBindCommand(Texture* texture) {
				this->texture = texture;
			}

			TextureBindCommand::~TextureBindCommand() {
			}

			void TextureBindCommand::execute() {
				app::api->bind(texture);
			}

			string TextureBindCommand::getName() const {
				return "TextureBind";
			}
		}
	}
}
