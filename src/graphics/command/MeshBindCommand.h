#pragma once
#include <common.h>
#include <graphics/command/Command.h>
#include <graphics/Mesh.h>

namespace spruce {
	class MeshBindCommand : public Command {
		public:
			Mesh* mesh;

			MeshBindCommand(Mesh* mesh);
			virtual ~MeshBindCommand();

			void execute();
			string getName();
	};
}
