#pragma once
#include <common.h>
#include <graphics/MeshRenderer.h>

namespace spruce {
	class MetalMeshRenderer: public MeshRenderer {
		public:
			MetalMeshRenderer();
			~MetalMeshRenderer();

			void render(Mesh* mesh, Shader* shader);
	};
}
