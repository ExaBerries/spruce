#include <graphics/command/shader/ShaderBindCommand.h>
#include <graphics/command/shader/ShaderUniformCommand.h>
#include <graphics/Shader.h>
#include <graphics/graphics.h>

namespace spruce {
	namespace graphics {
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

		uint16 Shader::getAttributeLocation(string name) {
			return 0;
		}

		void Shader::registerUniform(string name, ShaderUniformLocation location, uint16 index) {
			uniformLocations[name].location = location;
			uniformLocations[name].index = index;
		}

		void Shader::setUniform(string name, const int32& value) {
			graphics::getCommandBuffer().add(new ShaderUniformCommand(this, name, value));
		}

		void Shader::setUniform(string name, const vec2i& vector) {
			graphics::getCommandBuffer().add(new ShaderUniformCommand(this, name, vector));
		}

		void Shader::setUniform(string name, const float& value) {
			graphics::getCommandBuffer().add(new ShaderUniformCommand(this, name, value));
		}

		void Shader::setUniform(string name, const vec2f& vector) {
			graphics::getCommandBuffer().add(new ShaderUniformCommand(this, name, vector));
		}

		void Shader::setUniform(string name, const vec3f& vector) {
			graphics::getCommandBuffer().add(new ShaderUniformCommand(this, name, vector));
		}

		void Shader::setUniform(string name, const mat4f& matrix) {
			graphics::getCommandBuffer().add(new ShaderUniformCommand(this, name, matrix));
		}

		void Shader::setUniform(string name, const quaternion& quaternion) {
			graphics::getCommandBuffer().add(new ShaderUniformCommand(this, name, quaternion));
		}

		void Shader::setUniform(string name, const color& color) {
			graphics::getCommandBuffer().add(new ShaderUniformCommand(this, name, color));
		}

		void Shader::setUniform(string name, Texture* texture) {
			graphics::getCommandBuffer().add(new ShaderUniformCommand(this, name, texture));
		}

		void Shader::setUniform(string name, graphics::RenderPass* renderPass) {
			graphics::getCommandBuffer().add(new ShaderUniformCommand(this, name, renderPass));
		}
	}
}
