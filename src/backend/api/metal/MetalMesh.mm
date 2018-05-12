#include <backend/api/metal/MetalMesh.h>
#include <backend/api/metal/MetalContext.h>

namespace spruce {
	MetalMesh::MetalMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices) : Mesh(vertexCount, vertices, indexCount, indices) {
		bufferVertexCount = 0;
		bufferIndexCount = 0;
		vertexBuffer = nil;
		indexBuffer = nil;
	}

	MetalMesh::~MetalMesh() {
		freeVRAM();
	}

	void MetalMesh::toVRAM(Shader* shader) {
		if (vertexBuffer == nil && vertexCount != 0) {
			vertexBuffer = [device newBufferWithLength:(vertexCount * sizeof(float)) options:MTLResourceStorageModeManaged];
			bufferVertexCount = vertexCount;
		} else {
			if (vertexCount == 0) {
			} else if (bufferVertexCount != vertexCount) {
				//[vertexBuffer release];
				vertexBuffer = [device newBufferWithLength:(vertexCount * sizeof(float)) options:MTLResourceStorageModeManaged];
				bufferVertexCount = vertexCount;
			}
		}
		if (vertexCount > 0) {
			memcpy(vertexBuffer.contents, vertices, vertexCount * sizeof(float));
			[vertexBuffer didModifyRange:NSMakeRange(0, vertexCount * sizeof(float))];
		}
		if (indexBuffer == nil && indexCount != 0) {
			indexBuffer = [device newBufferWithLength:(indexCount * sizeof(uint16)) options:MTLResourceStorageModeManaged];
			bufferIndexCount = indexCount;
		} else {
			if (indexCount == 0) {
			} else if (bufferIndexCount != indexCount) {
				//[indexBuffer release];
				indexBuffer = [device newBufferWithLength:(indexCount * sizeof(uint16)) options:MTLResourceStorageModeManaged];
				bufferIndexCount = indexCount;
			}
		}
		if (indexCount > 0) {
			memcpy(indexBuffer.contents, indices, indexCount * sizeof(uint16));
			[indexBuffer didModifyRange:NSMakeRange(0, indexCount * sizeof(uint16))];
		}
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
