#include <graphics/Mesh.h>
#include <graphics/Shader.h>
#include <graphics/command/MeshBindCommand.h>
#include <graphics/graphics.h>

namespace spruce {
	Mesh::Mesh(buffer<float> vertices, buffer<uint16> indices) : vertices(vertices), indices(indices) {
	}

	Mesh::~Mesh() {
	}

	void Mesh::bind() {
		graphics::getCommandBuffer().add(new MeshBindCommand(this));
	}
}
