#pragma once
#include "Mesh.h"
#include "Shader.h"
#include "MeshRenderer.h"
#include "Camera.h"

namespace spruce {
	namespace graphics {
		Mesh* createMesh(int vertexCount, float* vertices, int indexCount, unsigned short* indices, Shader& shader);
		Shader* createShader(char* vertSource, char* fragSource, int attributesCount, VertexAttribute* attributes);
		MeshRenderer* createMeshRenderer();

		int getWidth();
		int getHeight();
	}
}
