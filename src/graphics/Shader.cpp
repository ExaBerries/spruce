#include <graphics/Shader.h>

namespace spruce {
	Shader::Shader(buffer<uint8> vertData, buffer<uint8> fragData, buffer<VertexAttribute> attributes) : vertData(vertData), fragData(fragData), attributes(attributes) {
		this->vertSource = string();
		this->fragSource = string();
	}

	Shader::Shader(const string& vertSource, const string& fragSource, buffer<VertexAttribute> attributes) : vertData(nullptr), fragData(nullptr), attributes(attributes) {
		this->vertSource = vertSource;
		this->fragSource = fragSource;
	}

	Shader::~Shader() {
		if (vertData.size > 0) {
			vertData.free();
		}
		if (fragData.size > 0) {
			fragData.free();
		}
	}
}
