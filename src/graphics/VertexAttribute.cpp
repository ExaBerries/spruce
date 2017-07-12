#include <graphics/VertexAttribute.h>

namespace spruce {
	VertexAttribute::VertexAttribute() : name("position"), size(3) {
	}

	VertexAttribute::VertexAttribute(string name, uint8 size) : name(name), size(size) {
	}
}
