#pragma once
#include <common.h>
#include <math.h>
#include <graphics/VertexAttribute.h>
#include <graphics/Camera.h>
#include <graphics/color.h>
#include <graphics/Texture.h>
#include <graphics/RenderPass.h>

namespace spruce {
	class Shader {
		public:
			buffer<uint8> vertData;
			string vertSource;
			buffer<uint8> fragData;
			string fragSource;
			buffer<VertexAttribute> attributes;

			Shader(buffer<uint8> vertData, buffer<uint8> fragData, buffer<VertexAttribute> attributes);
			Shader(const string& vertSource, const string& fragSource, buffer<VertexAttribute> attributes);
			Shader(const Shader& shader) = delete;
			virtual ~Shader();

			virtual void compile(graphics::RenderPass* renderPass) = 0;
			virtual void enable() = 0;
			virtual void disable() = 0;

			virtual uint16 getAttributeLocation(string name) = 0;
			virtual uint16 registerUniform(string name, uint16 index) = 0;

			virtual void setUniform(string name, const int& value) = 0;
			virtual void setUniform(string name, const vec2i& vector) = 0;
			virtual void setUniform(string name, const float& value) = 0;
			virtual void setUniform(string name, const vec2f& vector) = 0;
			virtual void setUniform(string name, const vec3f& vector) = 0;
			virtual void setUniform(string name, const mat4f& matrix) = 0;
			virtual void setUniform(string name, const quaternion& quaternion) = 0;
			virtual void setUniform(string name, const color& color) = 0;
			virtual void setUniform(string name, const Texture* texture) = 0;
			virtual void setUniform(string name, const graphics::RenderPass* renderPass) = 0;
	};
}
