#pragma once
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include "VertexAttribute.h"
#include "Camera.h"
#include "../math/vec2i.h"
#include "../math/vec2f.h"
#include "../math/vec3f.h"
#include "../math/mat4f.h"
#include "../math/quaternion.h"
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

			Shader(char* vertSource, char* fragSource, int attributesCount, VertexAttribute* attributes);
			virtual ~Shader();

			virtual void compile() = 0;
			virtual void enable() = 0;
			virtual void disable() = 0;

			virtual unsigned int getAttributeLocation(std::string name) = 0;
			virtual unsigned int registerUniform(std::string name) = 0;

			virtual void setUniform(std::string name, int& value) = 0;
			virtual void setUniform(std::string name, vec2i& vector) = 0;
			virtual void setUniform(std::string name, float& value) = 0;
			virtual void setUniform(std::string name, vec2f& vector) = 0;
			virtual void setUniform(std::string name, vec3f& vector) = 0;
			virtual void setUniform(std::string name, mat4f& matrix) = 0;
			virtual void setUniform(std::string name, quaternion& quaternion) = 0;
	};
}
