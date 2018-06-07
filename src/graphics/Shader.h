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
			enum ShaderUniformLocation {
				VERTEX, FRAGMENT
			};
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
			void bind();

			virtual uint16 getAttributeLocation(string name) = 0;
			virtual uint16 registerUniform(string name, uint16 index) = 0;

			void setUniform(string name, ShaderUniformLocation location, const int32& value);
			void setUniform(string name, ShaderUniformLocation location, const vec2i& vector);
			void setUniform(string name, ShaderUniformLocation location, const float& value);
			void setUniform(string name, ShaderUniformLocation location, const vec2f& vector);
			void setUniform(string name, ShaderUniformLocation location, const vec3f& vector);
			void setUniform(string name, ShaderUniformLocation location, const mat4f& matrix);
			void setUniform(string name, ShaderUniformLocation location, const quaternion& quaternion);
			void setUniform(string name, ShaderUniformLocation location, const color& color);
			void setUniform(string name, ShaderUniformLocation location, const Texture* texture);
			void setUniform(string name, ShaderUniformLocation location, const graphics::RenderPass* renderPass);
	};
}
