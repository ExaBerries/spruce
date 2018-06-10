#pragma once
#include <common.h>
#include <backend/api/opengl/platform.h>
#include <graphics/Mesh.h>

namespace spruce {
	class OpenGLMesh : public Mesh {
		public:
			GLuint vao;
			GLuint vbo;
			GLuint ibo;
			uint16 bufferVertexCount;
			uint16 bufferIndexCount;

			OpenGLMesh(buffer<float> vertices, buffer<uint16> indices);
			OpenGLMesh(const OpenGLMesh& mesh) = delete;
			~OpenGLMesh();

			void toVRAM(Shader* shader);
			void freeVRAM();
	};
}
