#pragma once
#include <graphics/command/Command.h>
#include <graphics/Mesh.h>
#include <graphics/Shader.h>

namespace spruce {
	class RenderMeshCommand: public Command {
		public:
			Mesh* mesh;
			Shader* shader;

			RenderMeshCommand(Mesh* mesh, Shader* shader);
			virtual ~RenderMeshCommand();

			void execute();
			string getName();
	};
}
