#include <backend/api/metal/MetalMesh.h>
#include <backend/api/metal/MetalContext.h>

namespace spruce {
	MetalMesh::MetalMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices) : Mesh(vertexCount, vertices, indexCount, indices) {
	}

	MetalMesh::~MetalMesh() {
		freeVRAM();
	}

	void MetalMesh::toVRAM(Shader* shader) {
		vertexBuffer = [device newBufferWithLength:(vertexCount * sizeof(float)) options:MTLResourceStorageModeManaged];
		memcpy(vertexBuffer.contents, vertices, vertexCount * sizeof(float));
		[vertexBuffer didModifyRange:NSMakeRange(0, vertexCount * sizeof(float))];
		indexBuffer = [device newBufferWithLength:(indexCount * sizeof(uint16)) options:MTLResourceStorageModeManaged];
		memcpy(indexBuffer.contents, indices, indexCount * sizeof(uint16));
		[indexBuffer didModifyRange:NSMakeRange(0, indexCount * sizeof(uint16))];
	}

	void MetalMesh::freeVRAM() {
		[vertexBuffer release];
		[indexBuffer release];
	}

	void MetalMesh::bind() {
	}

	void MetalMesh::unbind() {
	}
}
