#pragma once
#include <common.h>
#include <graphics/command/Command.h>
#include <graphics/Shader.h>

namespace spruce {
	namespace graphics {
		namespace cmd {
			class ShaderBindCommand: public Command {
				public:
					Shader* shader;

					ShaderBindCommand(Shader* shader);
					virtual ~ShaderBindCommand();

					void execute();
					string getName() const;
			};
		}
	}
}
