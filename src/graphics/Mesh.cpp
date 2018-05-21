#include <graphics/Mesh.h>
#include <graphics/Shader.h>
#include <graphics/command/MeshBindCommand.h>
#include <graphics/graphics.h>

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
		if (vertices != nullptr) {
			delete[] vertices;
		}
		if (indices != nullptr) {
			delete[] indices;
		}
	}

	void Mesh::bind() {
		graphics::getCommandBuffer().add(new MeshBindCommand(this));
	}
}
