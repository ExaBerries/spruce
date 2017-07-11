#pragma once
#include "../../graphics/Mesh.h"
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>

namespace spruce {
	class OpenGLMesh : public Mesh {
		public:
			GLuint vao;
			GLuint vbo;
			GLuint ibo;

			OpenGLMesh(int vertexCount, float* vertices, int indexCount, unsigned short* indices, Shader& shader);
			~OpenGLMesh();
			void toVRAM();
			void bind();
			void unbind();
	};
}
