#pragma once
#ifdef __APPLE__
#include <spruce.h>
#include <graphics/renderer/api/metal/metal.h>
#include <scene/basic/renderer/BasicRendererData.h>

using namespace spruce;

namespace sprucetest {
	class Basic;

	class BasicMetalRenderer : public MetalRenderer<Basic, BasicRendererData> {
		public:
			owner<MetalCommandQueue> queue;
			owner<MetalLibrary> library;
			owner<MetalFunction> vertFn;
			owner<MetalFunction> fragFn;
			owner<MetalRenderPipelineState> pipelineState;
			owner<MetalDepthStencilState> depthStencilState;

			BasicMetalRenderer(Application& app);
			~BasicMetalRenderer();

			BasicRendererData encode(Basic& encodeData) override;
			void execute(BasicRendererData& executeData) override;

			owner<MeshAPIData> createMeshAPIData(Mesh& mesh) override;
			owner<TextureAPIData> createTextureAPIData(Texture& texture) override;
	};
}
#endif
