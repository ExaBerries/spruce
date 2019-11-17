#include <scene/basic/renderer/metal/BasicMetalMeshData.h>
#ifdef __APPLE__

namespace sprucetest {
	BasicMetalMeshData::BasicMetalMeshData(Mesh& mesh, MetalContext& context) {
		vertexBuffer = context.device.createBuffer(mesh.vertices.size * sizeof(float), MetalResourceStorageMode::MANAGED);
		memcpy(vertexBuffer->getContents(), mesh.vertices.data, mesh.vertices.size * sizeof(float));
		vertexBuffer->didModifyRange(0, mesh.vertices.size * sizeof(float));
		if (mesh.indices.size > 0) {
			indexBuffer = context.device.createBuffer(mesh.indices.size * sizeof(uint16), MetalResourceStorageMode::MANAGED);
			memcpy(indexBuffer->getContents(), mesh.indices.data, mesh.indices.size * sizeof(uint16));
			indexBuffer->didModifyRange(0, mesh.indices.size * sizeof(uint16));
		}
	}

	BasicMetalMeshData::~BasicMetalMeshData() {
		delete (MetalBuffer*)vertexBuffer;
		delete (MetalBuffer*)indexBuffer;
	}
}
#endif
