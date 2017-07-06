#pragma once
#include <string>

namespace spruce {
	struct VertexAttribute {
		std::string name;
		int size;

		VertexAttribute();
		VertexAttribute(std::string name, int size);
	};
}
