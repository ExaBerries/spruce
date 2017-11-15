#pragma once
#include <common.h>
#include <math.h>
#include <graphics/VertexAttribute.h>
#include <graphics/Camera.h>
#include <graphics/color.h>

namespace spruce {
	class Shader {
		public:
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

			virtual void compile() = 0;
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
	};
}
