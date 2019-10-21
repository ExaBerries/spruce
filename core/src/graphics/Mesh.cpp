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

		void Mesh::toVRAM(RendererAbstractor* renderer) noexcept {
			apiData = renderer->createMeshAPIData(*this);
		}

		void Mesh::freeVRAM() noexcept {
			delete apiData;
			apiData = nullptr;
		}
	}
}
