#pragma once
#ifdef __APPLE__
#include <spruce.h>
#include <graphics/renderer/api/metal/metal.h>

using namespace spruce;

namespace sprucetest {
	class BasicMetalMeshData : public MeshAPIData {
		public:
			owner<MetalBuffer> vertexBuffer;
			owner<MetalBuffer> indexBuffer;

			BasicMetalMeshData(Mesh& mesh, MetalContext& context);
			~BasicMetalMeshData();
	};
}
#endif
