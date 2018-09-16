#include <graphics/command/mesh/MeshBindCommand.h>
#include <graphics/Mesh.h>
#include <graphics/Shader.h>
#include <graphics/graphics.h>

namespace spruce {
	namespace graphics {
		Mesh::Mesh(buffer<float> vertices, buffer<uint16> indices) : vertices(vertices), indices(indices) {
		}

		Mesh::~Mesh() {
			vertices.free();
			indices.free();
		}

		void Mesh::bind() {
			graphics::getCommandBuffer().add(new cmd::MeshBindCommand(this));
		}
	}
}
