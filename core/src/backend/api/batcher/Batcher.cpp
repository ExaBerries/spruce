#include <backend/api/batcher/Batcher.h>

namespace spruce {
	Batcher::Batcher(buffer<VertexAttribute> shaderAttributes, Shader* shader, uint64 maxVertices, uint64 maxIndices) : vertices(maxVertices), indices(maxIndices) {
		this->shaderAttributes = shaderAttributes;
		this->shader = shader;
		verticesIndex = 0;
		indicesIndex = 0;
		this->maxVertices = maxVertices;
		this->maxIndices = maxIndices;
	}

	Batcher::~Batcher() {
		shaderAttributes.free();
		if (shader != nullptr) {
			delete shader;
		};
		vertices.free();
		indices.free();
	}

	void Batcher::reset() {
		verticesIndex = 0;
		memset(vertices, 0, vertices.size);
		indicesIndex = 0;
		memset(indices, 0,  indices.size);
	}

	void Batcher::flush() {
		render();
		reset();
	}

	void Batcher::addVertex(float vertex) {
		if (verticesIndex + 1 < maxVertices) {
			vertices[verticesIndex++] = vertex;
		}
	}

	void Batcher::addVertices(buffer<float> vertices) {
		if (verticesIndex + vertices.size < maxVertices) {
			memcpy(this->vertices + verticesIndex, vertices, vertices.size * sizeof(float));
			verticesIndex += vertices.size;
		} else {
			uint64 i = 0;
			while (i < vertices.size) {
				uint64 amountToCopy = std::min(vertices.size - i, maxVertices);
				memcpy(this->vertices + verticesIndex, vertices + i, amountToCopy * sizeof(float));
				verticesIndex += amountToCopy;
				i += amountToCopy;
				if (verticesIndex == maxVertices) {
					flush();
				}
			}
		}
	}

	void Batcher::addIndex(uint16 index) {
		indices[indicesIndex++] = index;
	}

	void Batcher::addIndices(buffer<uint16> indices) {
		memcpy(this->indices + indicesIndex, indices, indices.size * sizeof(uint16));
		indicesIndex += indices.size * sizeof(uint16);
	}
}
