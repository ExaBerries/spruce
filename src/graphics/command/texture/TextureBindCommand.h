#pragma once
#include <common.h>
#include <graphics/command/Command.h>
#include <graphics/Texture.h>

namespace spruce {
	namespace graphics {
		namespace cmd {
			class TextureBindCommand : public Command {
				public:
					Texture* texture;

					TextureBindCommand(Texture* texture);
					virtual ~TextureBindCommand();

					void execute();
					string getName() const;
			};
		}
	}
}
