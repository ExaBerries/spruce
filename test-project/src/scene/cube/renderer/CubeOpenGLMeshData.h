#pragma once
#include <spruce.h>
#include <graphics/renderer/api/opengl/opengl.h>

using namespace spruce;

namespace sprucetest {
	class CubeOpenGLMeshData : public MeshAPIData {
		public:
			GLuint vao;
			GLuint vbo;
			GLuint ibo;
			uint16 vertexCount;
			uint16 indexCount;
			bool attribPointers;

			CubeOpenGLMeshData(Mesh& mesh);
			~CubeOpenGLMeshData();

			void bind();
	};
}
