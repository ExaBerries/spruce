#pragma once
#include <spruce.h>
#include <graphics/renderer/api/opengl/opengl.h>

using namespace spruce;

namespace sprucetest {
	class BasicMeshData : public MeshAPIData {
		public:
			GLuint vao;
			GLuint vbo;
			GLuint ibo;
			uint16 vertexCount;
			uint16 indexCount;

			BasicMeshData(Mesh& mesh);
			~BasicMeshData();

			void bind();
	};
}
