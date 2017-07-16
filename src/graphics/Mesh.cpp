#include <graphics/Mesh.h>
#include <graphics/Shader.h>

namespace spruce {
	Mesh::Mesh(const Mesh& mesh) {
		this->vertexCount = mesh.vertexCount;
		this->vertices = mesh.vertices;
		this->indexCount = mesh.indexCount;
		this->indices = mesh.indices;
	}

	Mesh::Mesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices) {
		this->vertexCount = vertexCount;
		this->vertices = vertices;
		this->indexCount = indexCount;
		this->indices = indices;
	}

	Mesh::~Mesh() {
		delete[] vertices;
		delete[] indices;
	}
}
