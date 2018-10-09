#pragma once
#include <common.h>
#include <graphics/Mesh.h>
#include <backend/api/metal/Metal.h>
#include <Metal/Metal.h>

namespace spruce {
	class MetalMesh : public Mesh {
		public:
			MetalContext& context;
			id<MTLBuffer> vertexBuffer;
			id<MTLBuffer> indexBuffer;
			uint16 bufferVertexCount;
			uint16 bufferIndexCount;

			MetalMesh(buffer<float> vertices, buffer<uint16> indices, MetalContext& context);
			MetalMesh(const MetalMesh& mesh) = delete;
			~MetalMesh();

			void toVRAM(Shader* shader);
			void freeVRAM();
	};
}
