#pragma once
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include "VertexAttribute.h"

namespace spruce {
	class Mesh;

	class Shader {
		public:
			GLuint vert;
			GLuint frag;
			GLuint program;
			char* vertSource;
			char* fragSource;
			int attributesCount;
			VertexAttribute* attributes;

			Shader(char* vertSource, char* fragSource, int attributesCount, VertexAttribute* attributes);
			virtual ~Shader();

			void compile();
			void enable();
			void disable();
			void render(Mesh& mesh);

			int getAttributeLocation(std::string name);
	};
}
