#include "Mesh.h"
#include "Shader.h"
#include "../log.h"

namespace spruce {
	Mesh::Mesh(int vertexCount, float* vertices, int indexCount, unsigned short* indices, Shader& shader) : shader(shader) {
		this->vertexCount = vertexCount;
		this->vertices = vertices;
		this->indexCount = indexCount;
		this->indices = indices;
	}

	Mesh::~Mesh() {
	}
}
