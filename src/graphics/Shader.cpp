#include <graphics/Shader.h>

namespace spruce {
	Shader::Shader(const Shader& shader) {
		this->vertData = shader.vertData;
		this->vertDataSize = shader.vertDataSize;
		this->vertSource = shader.vertSource;
		this->fragData = shader.fragData;
		this->fragDataSize = shader.fragDataSize;
		this->fragSource = shader.fragSource;
		this->attributeCount = shader.attributeCount;
		this->attributes = shader.attributes;
	}

	Shader::Shader(uint8* vertData, uint16 vertDataSize, uint8* fragData, uint16 fragDataSize, uint16 attributeCount, VertexAttribute* attributes) {
		this->vertData = vertData;
		this->vertDataSize = vertDataSize;
		this->vertSource = string();
		this->fragData = fragData;
		this->fragDataSize = fragDataSize;
		this->fragSource = string();
		this->attributeCount = attributeCount;
		this->attributes = attributes;
	}

	Shader::Shader(const string& vertSource, const string& fragSource, uint16 attributeCount, VertexAttribute* attributes) {
		this->vertData = nullptr;
		this->vertDataSize = 0;
		this->vertSource = vertSource;
		this->fragData = nullptr;
		this->fragDataSize = 0;
		this->fragSource = fragSource;
		this->attributeCount = attributeCount;
		this->attributes = attributes;
	}

	Shader::~Shader() {
		if (vertDataSize > 0) {
			delete[] vertData;
		}
		if (fragDataSize > 0) {
			delete[] fragData;
		}
	}
}
