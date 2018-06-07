#pragma once
#include <common.h>
#include <graphics/Shader.h>
#include <Metal/Metal.h>

namespace spruce {
	class MetalShader : public Shader {
		public:
			id<MTLRenderPipelineState> pipelineState;
			id<MTLLibrary> library;
			id<MTLFunction> vertexFunction;
			id<MTLFunction> fragmentFunction;
			std::map<string, uint16> uniformLocations;

			MetalShader(buffer<uint8> vertData, buffer<uint8> fragData, buffer<VertexAttribute> attributes);
			MetalShader(const string& vertSource, const string& fragSource, buffer<VertexAttribute> attributes);
			MetalShader(const MetalShader& shader) = delete;
			~MetalShader();

			void compileData();
			void compileSource();
			void compile(graphics::RenderPass* renderPass);

			uint16 getAttributeLocation(string name);
			uint16 registerUniform(string name, uint16 index);
	};
}
