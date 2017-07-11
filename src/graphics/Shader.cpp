#include "Shader.h"
#include "Mesh.h"
#include <string>
#include <vector>
#include "../log.h"

namespace spruce {
	Shader::Shader(char* vertSource, char* fragSource, int attributesCount, VertexAttribute* attributes) {
		this->vertSource = vertSource;
		this->fragSource = fragSource;
		this->attributeCount = attributesCount;
		this->attributes = attributes;
	}

	Shader::~Shader() {
	}
}
