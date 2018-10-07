#include <graphics/command/texture/TextureUnbindCommand.h>
#include <app.h>

namespace spruce {
	namespace graphics {
		namespace cmd {
			TextureUnbindCommand::TextureUnbindCommand(Texture* texture) {
				this->texture = texture;
			}

			TextureUnbindCommand::~TextureUnbindCommand() {
			}

			void TextureUnbindCommand::execute() {
				app::api->unbind(texture);
			}

			string TextureUnbindCommand::getName() const {
				return "TextureUnbind";
			}
		}
	}
}
