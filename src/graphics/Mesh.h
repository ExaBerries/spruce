#pragma once
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>

namespace spruce {
	class Mesh {
		public:
			GLuint vao;
			GLuint vbo;
			GLuint ibo;
			int vertexCount;
			float* vertices;
			int indexCount;
			short* indices;

			Mesh(int vertexCount, float* vertices, int indexCount, short* indices);
			virtual ~Mesh();
			void toVRAM();
	};
}
