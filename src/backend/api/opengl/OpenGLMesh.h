#pragma once
#include <common.h>
#include <graphics/Mesh.h>
#include <OpenGL/gl3.h>

namespace spruce {
	class OpenGLMesh : public Mesh {
		public:
			GLuint vao;
			GLuint vbo;
			GLuint ibo;

			OpenGLMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices);
			~OpenGLMesh();
			void toVRAM(Shader* shader);
			void freeVRAM();
			void bind();
			void unbind();
	};
}
