#include <backend/api/metal/MetalMesh.h>
#include <backend/api/metal/MetalContext.h>

namespace spruce {
	MetalMesh::MetalMesh(buffer<float> vertices, buffer<uint16> indices, MetalContext& context) : Mesh(vertices, indices), context(context) {
		bufferVertexCount = 0;
		bufferIndexCount = 0;
		vertexBuffer = nil;
		indexBuffer = nil;
	}

	MetalMesh::~MetalMesh() {
		freeVRAM();
	}

	void MetalMesh::toVRAM(Shader* shader) {
		if (vertexBuffer == nil && vertices.size != 0) {
			vertexBuffer = [context.device newBufferWithLength:(vertices.size * sizeof(float)) options:MTLResourceStorageModeManaged];
			bufferVertexCount = vertices.size;
		} else {
			if (vertices.size == 0) {
				[vertexBuffer release];
				bufferVertexCount = 0;
			} else if (bufferVertexCount != vertices.size) {
				[vertexBuffer release];
				vertexBuffer = [context.device newBufferWithLength:(vertices.size * sizeof(float)) options:MTLResourceStorageModeManaged];
				bufferVertexCount = vertices.size;
			}
		}
		if (vertices.size > 0) {
			memcpy(vertexBuffer.contents, vertices.data, vertices.size * sizeof(float));
			[vertexBuffer didModifyRange:NSMakeRange(0, vertices.size * sizeof(float))];
		}
		if (indexBuffer == nil && indices.size != 0) {
			indexBuffer = [context.device newBufferWithLength:(indices.size * sizeof(uint16)) options:MTLResourceStorageModeManaged];
			bufferIndexCount = indices.size;
		} else {
			if (indices.size == 0) {
				[indexBuffer release];
				bufferIndexCount = 0;
			} else if (bufferIndexCount != indices.size) {
				[indexBuffer release];
				indexBuffer = [context.device newBufferWithLength:(indices.size * sizeof(uint16)) options:MTLResourceStorageModeManaged];
				bufferIndexCount = indices.size;
			}
		}
		if (indices.size > 0) {
			memcpy(indexBuffer.contents, indices.data, indices.size * sizeof(uint16));
			[indexBuffer didModifyRange:NSMakeRange(0, indices.size * sizeof(uint16))];
		}
	}

	void MetalMesh::freeVRAM() {
		[vertexBuffer release];
		[indexBuffer release];
	}
}
