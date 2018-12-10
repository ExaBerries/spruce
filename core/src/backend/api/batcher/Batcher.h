#pragma once
#include <common.h>
#include <graphics/VertexAttribute.h>
#include <graphics/Shader.h>

namespace spruce {
	class Batcher {
		public:
			buffer<VertexAttribute> shaderAttributes;
			Shader* shader;
			uint64 maxVertices;
			uint64 maxIndices;
			buffer<float> vertices;
			buffer<uint16> indices;
			uint64 verticesIndex;
			uint64 indicesIndex;

			Batcher(buffer<VertexAttribute> shaderAttributes, Shader* shaders, uint64 maxVertices, uint64 maxIndices);
			virtual ~Batcher();

			virtual void render() = 0;

			void reset();
			void flush();
			void addVertex(float vertex);
			void addVertices(buffer<float> vertices);
			void addIndex(uint16 index);
			void addIndices(buffer<uint16> indices);
	};
}
