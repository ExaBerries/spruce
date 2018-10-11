#pragma once
#include <common.h>
#include <graphics/Shader.h>
#include <backend/api/metal/MetalContext.h>
#include <Metal/Metal.h>

namespace spruce {
	class MetalShader : public Shader {
		public:
			MetalContext& context;
			id<MTLRenderPipelineState> pipelineState;
			id<MTLLibrary> library;
			id<MTLFunction> vertexFunction;
			id<MTLFunction> fragmentFunction;

			MetalShader(buffer<uint8> vertData, buffer<uint8> fragData, buffer<VertexAttribute> attributes, MetalContext& context);
			MetalShader(const string& vertSource, const string& fragSource, buffer<VertexAttribute> attributes, MetalContext& context);
			MetalShader(const MetalShader& shader) = delete;
			~MetalShader();

			void compileData();
			void compileSource();
			void compile(graphics::RenderPass* renderPass);
	};
}
