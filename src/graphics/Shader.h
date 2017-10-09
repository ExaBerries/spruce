#pragma once
#include <common.h>
#include <math.h>
#include <graphics/VertexAttribute.h>
#include <graphics/Camera.h>
#include <map>

namespace spruce {
	class Shader {
		public:
			string vertSource;
			string fragSource;
			int attributeCount;
			VertexAttribute* attributes;

			Shader(const Shader& shader);
			Shader(const string& vertSource, const string& fragSource, uint16 attributeCount, VertexAttribute* attributes);
			virtual ~Shader();

			virtual void compile() = 0;
			virtual void enable() = 0;
			virtual void disable() = 0;

			virtual uint16 getAttributeLocation(string name) = 0;
			virtual uint16 registerUniform(string name) = 0;

			virtual void setUniform(string name, const int& value) = 0;
			virtual void setUniform(string name, const vec2i& vector) = 0;
			virtual void setUniform(string name, const float& value) = 0;
			virtual void setUniform(string name, const vec2f& vector) = 0;
			virtual void setUniform(string name, const vec3f& vector) = 0;
			virtual void setUniform(string name, const mat4f& matrix) = 0;
			virtual void setUniform(string name, const quaternion& quaternion) = 0;
	};
}
