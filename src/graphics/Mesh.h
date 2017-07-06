#pragma once
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>

namespace spruce {
	class Shader;

	class Mesh {
		public:
			GLuint vao;
			GLuint vbo;
			GLuint ibo;
			int vertexCount;
			float* vertices;
			int indexCount;
			unsigned short* indices;
			Shader& shader;

			Mesh(int vertexCount, float* vertices, int indexCount, unsigned short* indices, Shader& shader);
			virtual ~Mesh();
			void toVRAM();
			void bind();
			void unbind();
	};
}
