#pragma once
#include <common.h>
#include <graphics/VertexAttribute.h>
#include <graphics/Camera.h>
#include <math/vec2i.h>
#include <math/vec2f.h>
#include <math/vec3f.h>
#include <math/mat4f.h>
#include <math/quaternion.h>
#include <map>

namespace spruce {
	class Shader {
		public:
			string vertSource;
			string fragSource;
			int attributeCount;
			VertexAttribute* attributes;

			Shader(const Shader& shader);
			Shader(string& vertSource, string& fragSource, uint16 attributeCount, VertexAttribute* attributes);
			virtual ~Shader();

			virtual void compile() = 0;
			virtual void enable() = 0;
			virtual void disable() = 0;

			virtual uint16 getAttributeLocation(string name) = 0;
			virtual uint16 registerUniform(string name) = 0;

			virtual void setUniform(string name, int& value) = 0;
			virtual void setUniform(string name, vec2i& vector) = 0;
			virtual void setUniform(string name, float& value) = 0;
			virtual void setUniform(string name, vec2f& vector) = 0;
			virtual void setUniform(string name, vec3f& vector) = 0;
			virtual void setUniform(string name, mat4f& matrix) = 0;
			virtual void setUniform(string name, quaternion& quaternion) = 0;
	};
}
