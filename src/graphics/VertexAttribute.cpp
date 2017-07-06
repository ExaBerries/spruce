#include "VertexAttribute.h"

namespace spruce {
	VertexAttribute::VertexAttribute() : name("position"), size(3) {
	}

	VertexAttribute::VertexAttribute(std::string name, int size) : name(name), size(size) {
	}
}
