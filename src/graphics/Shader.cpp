#include <graphics/Shader.h>

namespace spruce {
	Shader::Shader(const Shader& shader) {
		this->vertSource = shader.vertSource;
		this->fragSource = shader.fragSource;
		this->attributeCount = shader.attributeCount;
		this->attributes = shader.attributes;
	}

	Shader::Shader(const string& vertSource, const string& fragSource, uint16 attributeCount, VertexAttribute* attributes) {
		this->vertSource = vertSource;
		this->fragSource = fragSource;
		this->attributeCount = attributeCount;
		this->attributes = attributes;
	}

	Shader::~Shader() {
	}
}
