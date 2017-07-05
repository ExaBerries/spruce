#pragma once
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include <string>

namespace spruce {
	class Shader {
		public:
			GLuint vert;
			GLuint frag;
			GLuint program;
			char* vertSource;
			char* fragSource;

			Shader(char* vertSource, char* fragSource);
			virtual ~Shader();

			void compile();
	};
}
