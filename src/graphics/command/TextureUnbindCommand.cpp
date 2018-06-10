#include <graphics/command/TextureUnbindCommand.h>
#include <app.h>
#include <backend/api/RenderAPI.h>

namespace spruce {
	TextureUnbindCommand::TextureUnbindCommand(Texture* texture) {
		this->texture = texture;
	}

	TextureUnbindCommand::~TextureUnbindCommand() {
	}

	void TextureUnbindCommand::execute() {
		app::api->unbind(texture);
	}

	string TextureUnbindCommand::getName() {
		return "TextureUnbind";
	}
}
