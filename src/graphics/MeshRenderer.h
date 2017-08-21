#pragma once
#include <common.h>
#include <graphics/Mesh.h>

namespace spruce {
	class MeshRenderer {
		public:
			virtual ~MeshRenderer();
			virtual void render(Mesh* mesh, Shader* shader) = 0;
	};
}
