#pragma once
#include <common.h>
#include <graphics/Shader.h>
#include <GLFW/glfw3.h>

namespace spruce {
	class OpenGLShader : public Shader {
		public:
			GLuint vert;
			GLuint frag;
			GLuint program;
			std::map<string, uint16> uniformLocations;

			OpenGLShader(const string& vertSource, const string& fragSource, uint16 attributesCount, VertexAttribute* attributes);
			~OpenGLShader();

			void compile();
			void enable();
			void disable();

			uint16 getAttributeLocation(string name);
			uint16 registerUniform(string name);

			void setUniform(string name, const int& value);
			void setUniform(string name, const vec2i& vector);
			void setUniform(string name, const float& value);
			void setUniform(string name, const vec2f& vector);
			void setUniform(string name, const vec3f& vector);
			void setUniform(string name, const mat4f& matrix);
			void setUniform(string name, const quaternion& quaternion);
	};
}
