#pragma once
#include <common.h>
#include <graphics/Mesh.h>
#include <Metal/Metal.h>

namespace spruce {
	class MetalMesh : public Mesh {
		public:
			id<MTLBuffer> vertexBuffer;
			id<MTLBuffer> indexBuffer;

			MetalMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices);
			~MetalMesh();
			void toVRAM(Shader* shader);
			void freeVRAM();
			void bind();
			void unbind();
	};
}
