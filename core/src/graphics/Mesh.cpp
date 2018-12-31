#include <graphics/Mesh.h>
#include <graphics/renderer/RendererAbstractor.h>

namespace spruce {
	namespace graphics {
		Mesh::Mesh(buffer<float>& vertices, buffer<uint16>& indices) {
			this->vertices = vertices;
			this->indices = indices;
			this->apiData = nullptr;
		}

		Mesh::~Mesh() {
			freeVRAM();
			vertices.free();
			indices.free();
		}

		void Mesh::toVRAM(RendererAbstractor* renderer) {
			apiData = renderer->createMeshAPIData(*this);
		}

		void Mesh::freeVRAM() {
			delete apiData;
		}
	}
}
