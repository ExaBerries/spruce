#include <app.h>
#include <backend/api/RenderAPI.h>
#include <graphics/command/shader/ShaderBindCommand.h>

namespace spruce {
	namespace graphics {
		namespace cmd {
			ShaderBindCommand::ShaderBindCommand(Shader* shader) {
				this->shader = shader;
			}

			ShaderBindCommand::~ShaderBindCommand() {
			}

			void ShaderBindCommand::execute() {
				app::api->bind(shader);
			}

			string ShaderBindCommand::getName() const {
				return "ShaderBind";
			}
		}
	}
}
