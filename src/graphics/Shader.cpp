#include <graphics/Shader.h>
#include <graphics/graphics.h>
#include <graphics/command/ShaderUniformCommand.h>
#include <graphics/command/ShaderBindCommand.h>

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

	void Shader::bind() {
		graphics::getCommandBuffer().add(new ShaderBindCommand(this));
	}

	void Shader::setUniform(string name, Shader::ShaderUniformLocation location, const int32& value) {
		graphics::getCommandBuffer().add(new ShaderUniformCommand(this, name, location, value));
	}

	void Shader::setUniform(string name, Shader::ShaderUniformLocation location, const vec2i& vector) {
		graphics::getCommandBuffer().add(new ShaderUniformCommand(this, name, location, vector));
	}

	void Shader::setUniform(string name, Shader::ShaderUniformLocation location, const float& value) {
		graphics::getCommandBuffer().add(new ShaderUniformCommand(this, name, location, value));
	}

	void Shader::setUniform(string name, Shader::ShaderUniformLocation location, const vec2f& vector) {
		graphics::getCommandBuffer().add(new ShaderUniformCommand(this, name, location, vector));
	}

	void Shader::setUniform(string name, Shader::ShaderUniformLocation location, const vec3f& vector) {
		graphics::getCommandBuffer().add(new ShaderUniformCommand(this, name, location, vector));
	}

	void Shader::setUniform(string name, Shader::ShaderUniformLocation location, const mat4f& matrix) {
		graphics::getCommandBuffer().add(new ShaderUniformCommand(this, name, location, matrix));
	}

	void Shader::setUniform(string name, Shader::ShaderUniformLocation location, const quaternion& quaternion) {
		graphics::getCommandBuffer().add(new ShaderUniformCommand(this, name, location, quaternion));
	}

	void Shader::setUniform(string name, Shader::ShaderUniformLocation location, const color& color) {
		graphics::getCommandBuffer().add(new ShaderUniformCommand(this, name, location, color));
	}

	void Shader::setUniform(string name, Shader::ShaderUniformLocation location, const Texture* texture) {
		graphics::getCommandBuffer().add(new ShaderUniformCommand(this, name, location, texture));
	}

	void Shader::setUniform(string name, Shader::ShaderUniformLocation location, const graphics::RenderPass* renderPass) {
		graphics::getCommandBuffer().add(new ShaderUniformCommand(this, name, location, renderPass));
	}
}
