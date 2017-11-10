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

			MetalShader(const string& vertSource, const string& fragSource, uint16 attributesCount, VertexAttribute* attributes);
			~MetalShader();

			void compile();
			void enable();
			void disable();

			uint16 getAttributeLocation(string name);
			uint16 registerUniform(string name, uint16 index);

			void setUniform(string name, const int& value);
			void setUniform(string name, const vec2i& vector);
			void setUniform(string name, const float& value);
			void setUniform(string name, const vec2f& vector);
			void setUniform(string name, const vec3f& vector);
			void setUniform(string name, const mat4f& matrix);
			void setUniform(string name, const quaternion& quaternion);
			void setUniform(string name, const color& color);
	};
}
