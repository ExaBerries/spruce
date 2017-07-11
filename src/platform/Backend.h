#pragma once
#include "../graphics/Mesh.h"
#include "../graphics/Shader.h"
#include "../graphics/MeshRenderer.h"
#include "../graphics/Camera.h"

namespace spruce {
	class Backend {
		public:
			virtual void init() = 0;
			virtual void run() = 0;

			virtual Mesh* createMesh(int vertexCount, float* vertices, int indexCount, unsigned short* indices, Shader& shader) = 0;
			virtual Shader* createShader(char* vertSource, char* fragSource, int attributesCount, VertexAttribute* attributes) = 0;
			virtual MeshRenderer* createMeshRenderer() = 0;
			// TODO virtual Texture* createTexture() = 0;

			virtual int getWindowWidth() = 0;
			virtual int getWindowHeight() = 0;
	};
}
