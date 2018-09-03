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
			struct UniformData {
				ShaderUniformLocation location;
				uint16 index;
			};
			buffer<uint8> vertData;
			string vertSource;
			buffer<uint8> fragData;
			string fragSource;
			buffer<VertexAttribute> attributes;
			std::map<string, UniformData> uniformLocations;

			Shader(buffer<uint8> vertData, buffer<uint8> fragData, buffer<VertexAttribute> attributes);
			Shader(const string& vertSource, const string& fragSource, buffer<VertexAttribute> attributes);
			Shader(const Shader& shader) = delete;
			virtual ~Shader();

			virtual void compile(graphics::RenderPass* renderPass) = 0;
			void bind();

			virtual uint16 getAttributeLocation(string name);
			virtual void registerUniform(string name, ShaderUniformLocation location, uint16 index);

			void setUniform(string name, const int32& value);
			void setUniform(string name, const vec2i& vector);
			void setUniform(string name, const float& value);
			void setUniform(string name, const vec2f& vector);
			void setUniform(string name, const vec3f& vector);
			void setUniform(string name, const mat4f& matrix);
			void setUniform(string name, const quaternion& quaternion);
			void setUniform(string name, const color& color);
			void setUniform(string name, Texture* texture);
			void setUniform(string name, graphics::RenderPass* renderPass);
	};
}
