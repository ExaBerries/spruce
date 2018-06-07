#include <graphics/Mesh.h>
#include <graphics/Shader.h>

namespace spruce {
	Mesh::Mesh(buffer<float> vertices, buffer<uint16> indices) : vertices(vertices), indices(indices) {
	}

	Mesh::~Mesh() {
	}
}
