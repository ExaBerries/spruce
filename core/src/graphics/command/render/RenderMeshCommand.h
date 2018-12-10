#pragma once
#include <graphics/command/Command.h>
#include <graphics/Mesh.h>
#include <graphics/Shader.h>
#include <graphics/Primitive.h>

namespace spruce {
	namespace graphics {
		namespace cmd {
			class RenderMeshCommand: public Command {
				public:
					Mesh* mesh;
					Shader* shader;
					graphics::Primitive primitive;

					RenderMeshCommand(Mesh* mesh, Shader* shader, graphics::Primitive primitive);
					virtual ~RenderMeshCommand();

					void execute();
					string getName() const;
			};
		}
	}
}
