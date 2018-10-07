#include <graphics/command/texture/TextureBindCommand.h>
#include <app.h>

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
