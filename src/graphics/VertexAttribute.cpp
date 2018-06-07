#include <graphics/VertexAttribute.h>

namespace spruce {
	VertexAttribute::VertexAttribute() : name("null"), size(0) {
	}

	VertexAttribute::VertexAttribute(string name, uint8 size) : name(name), size(size) {
	}

	VertexAttribute::VertexAttribute(const VertexAttribute& vertexAttribute) : name(vertexAttribute.name), size(vertexAttribute.size) {
	}

	VertexAttribute::~VertexAttribute() {
	}
}
