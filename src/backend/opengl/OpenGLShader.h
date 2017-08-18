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

			OpenGLShader(string& vertSource, string& fragSource, uint16 attributesCount, VertexAttribute* attributes);
			~OpenGLShader();

			void compile();
			void enable();
			void disable();

			uint16 getAttributeLocation(string name);
			uint16 registerUniform(string name);

			void setUniform(string name, int& value);
			void setUniform(string name, vec2i& vector);
			void setUniform(string name, float& value);
			void setUniform(string name, vec2f& vector);
			void setUniform(string name, vec3f& vector);
			void setUniform(string name, mat4f& matrix);
			void setUniform(string name, quaternion& quaternion);
	};
}
