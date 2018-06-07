#include <graphics/Shader.h>
#include <graphics/graphics.h>
#include <graphics/command/ShaderUniformCommand.h>
#include <graphics/command/ShaderBindCommand.h>

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
