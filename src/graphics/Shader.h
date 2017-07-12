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
	class Mesh;

	class Shader {
		public:
			char* vertSource;
			char* fragSource;
			int attributeCount;
			VertexAttribute* attributes;
			std::map<std::string, int> uniformLocations;

			virtual ~Shader();

			virtual void compile() = 0;
			virtual void enable() = 0;
			virtual void disable() = 0;

			virtual unsigned int getAttributeLocation(string name) = 0;
			virtual unsigned int registerUniform(string name) = 0;

			virtual void setUniform(string name, int& value) = 0;
			virtual void setUniform(string name, vec2i& vector) = 0;
			virtual void setUniform(string name, float& value) = 0;
			virtual void setUniform(string name, vec2f& vector) = 0;
			virtual void setUniform(string name, vec3f& vector) = 0;
			virtual void setUniform(string name, mat4f& matrix) = 0;
			virtual void setUniform(string name, quaternion& quaternion) = 0;
	};
}
