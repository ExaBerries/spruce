#include <scene/cube/renderer/CubeOpenGLMeshData.h>
#include <graphics/Mesh.h>

namespace sprucetest {
	CubeOpenGLMeshData::CubeOpenGLMeshData(Mesh& mesh) {
		vertexCount = mesh.vertices.size;
		indexCount = mesh.indices.size;
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(float), mesh.vertices.data, GL_DYNAMIC_DRAW);

		if (mesh.indices.size > 0) {
			glGenBuffers(1, &ibo);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(uint16), mesh.indices.data, GL_DYNAMIC_DRAW);
		}
		attribPointers = false;
	}

	CubeOpenGLMeshData::~CubeOpenGLMeshData() {
		glDeleteBuffers(1, &vbo);
		if (ibo > 0) {
			glDeleteBuffers(1, &ibo);
		}
		glDeleteVertexArrays(1, &vao);
	}

	void CubeOpenGLMeshData::bind() {
		glBindVertexArray(vao);
		if (ibo > 0) {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		}
	}
}
