#pragma once
#include <common.h>
#include <graphics/Shader.h>

namespace spruce {
	class OpenGLShader : public Shader {
		public:
			GLuint vert;
			GLuint frag;
			GLuint program;

			OpenGLShader(char* vertSource, char* fragSource, uint16 attributesCount, VertexAttribute* attributes);
			virtual ~OpenGLShader();

			void compile();
			void enable();
			void disable();
			void render(Mesh& mesh);

			unsigned int getAttributeLocation(string name);
			unsigned int registerUniform(string name);

			void setUniform(string name, int& value);
			void setUniform(string name, vec2i& vector);
			void setUniform(string name, float& value);
			void setUniform(string name, vec2f& vector);
			void setUniform(string name, vec3f& vector);
			void setUniform(string name, mat4f& matrix);
			void setUniform(string name, quaternion& quaternion);
	};
}
