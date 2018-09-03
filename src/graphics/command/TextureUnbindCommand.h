#pragma once
#include <graphics/command/Command.h>
#include <graphics/Texture.h>

namespace spruce {
	class TextureUnbindCommand: public Command {
		public:
			Texture* texture;

			TextureUnbindCommand(Texture* texture);
			virtual ~TextureUnbindCommand();

			void execute();
			string getName() const;
	};
}
