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
			uint8* vertData;
			uint16 vertDataSize;
			string vertSource;
			uint8* fragData;
			uint16 fragDataSize;
			string fragSource;
			int attributeCount;
			VertexAttribute* attributes;

			Shader(const Shader& shader);
			Shader(uint8* vertData, uint16 vertDataSize, uint8* fragData, uint16 fragDataSize, uint16 attributeCount, VertexAttribute* attributes);
			Shader(const string& vertSource, const string& fragSource, uint16 attributeCount, VertexAttribute* attributes);
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
