#pragma once
#include "../../graphics/Shader.h"

namespace spruce {
	class OpenGLShader : public Shader {
		public:
			GLuint vert;
			GLuint frag;
			GLuint program;

			OpenGLShader(char* vertSource, char* fragSource, int attributesCount, VertexAttribute* attributes);
			virtual ~OpenGLShader();

			void compile();
			void enable();
			void disable();
			void render(Mesh& mesh);

			unsigned int getAttributeLocation(std::string name);
			unsigned int registerUniform(std::string name);

			void setUniform(std::string name, int& value);
			void setUniform(std::string name, vec2i& vector);
			void setUniform(std::string name, float& value);
			void setUniform(std::string name, vec2f& vector);
			void setUniform(std::string name, vec3f& vector);
			void setUniform(std::string name, mat4f& matrix);
			void setUniform(std::string name, quaternion& quaternion);
	};
}
