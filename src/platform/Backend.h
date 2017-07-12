#pragma once
#include <common.h>
#include <graphics/Mesh.h>
#include <graphics/Shader.h>
#include <graphics/MeshRenderer.h>
#include <graphics/Texture.h>
#include <graphics/Camera.h>

namespace spruce {
	class Backend {
		public:
			virtual void init() = 0;
			virtual void run() = 0;

			virtual Mesh* createMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices, Shader* shader) = 0;
			virtual Shader* createShader(char* vertSource, char* fragSource, uint16 attributesCount, VertexAttribute* attributes) = 0;
			virtual MeshRenderer* createMeshRenderer() = 0;
			virtual Texture* createTexture(string& string) = 0;

			virtual int getWindowWidth() = 0;
			virtual int getWindowHeight() = 0;
	};
}
