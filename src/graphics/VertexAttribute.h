#pragma once
#include <common.h>
#include <string>

namespace spruce {
	struct VertexAttribute {
		std::string name;
		uint8 size;

		VertexAttribute();
		VertexAttribute(string name, uint8 size);
	};
}
