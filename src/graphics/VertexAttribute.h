#pragma once
#include <common.h>
#include <string>

namespace spruce {
	struct VertexAttribute {
		string name;
		uint8 size;

		VertexAttribute();
		VertexAttribute(string name, uint8 size);
		VertexAttribute(const VertexAttribute& vertexAttribute);
		~VertexAttribute();
	};
}
