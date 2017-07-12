#pragma once
#include "../../graphics/MeshRenderer.h"

namespace spruce {
	class OpenGLMeshRenderer: public MeshRenderer {
		public:
			OpenGLMeshRenderer();
			virtual ~OpenGLMeshRenderer();

			void render(Mesh& mesh, Shader& shader);
	};
}