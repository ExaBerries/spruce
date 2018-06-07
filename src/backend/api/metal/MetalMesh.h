#pragma once
#include <common.h>
#include <graphics/Mesh.h>
#include <Metal/Metal.h>

namespace spruce {
	class MetalMesh : public Mesh {
		public:
			id<MTLBuffer> vertexBuffer;
			id<MTLBuffer> indexBuffer;
			uint16 bufferVertexCount;
			uint16 bufferIndexCount;

			MetalMesh(buffer<float> vertices, buffer<uint16> indices);
			MetalMesh(const MetalMesh& mesh) = delete;
			~MetalMesh();

			void toVRAM(Shader* shader);
			void freeVRAM();
			void bind();
			void unbind();
	};
}
