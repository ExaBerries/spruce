#include <backend/api/metal/MetalMeshRenderer.h>
#include <backend/api/metal/MetalContext.h>
#include <backend/api/metal/MetalMesh.h>

namespace spruce {
	MetalMeshRenderer::MetalMeshRenderer() {
	}

	MetalMeshRenderer::~MetalMeshRenderer() {
	}

	void MetalMeshRenderer::render(Mesh* mesh, Shader* shader) {
		[renderEncoder setVertexBuffer:((MetalMesh*)mesh)->vertexBuffer offset:0 atIndex:0];
		[renderEncoder drawIndexedPrimitives:MTLPrimitiveTypeTriangle indexCount:((MetalMesh*)mesh)->indexCount indexType:MTLIndexTypeUInt16 indexBuffer:((MetalMesh*)mesh)->indexBuffer indexBufferOffset:0];
	}
}
