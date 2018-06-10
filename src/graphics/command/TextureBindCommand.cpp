#include <graphics/command/TextureBindCommand.h>
#include <app.h>
#include <backend/api/RenderAPI.h>

namespace spruce {
	TextureBindCommand::TextureBindCommand(Texture* texture) {
		this->texture = texture;
	}

	TextureBindCommand::~TextureBindCommand() {
	}

	void TextureBindCommand::execute() {
		app::api->bind(texture);
	}

	string TextureBindCommand::getName() {
		return "TextureBind";
	}
}
