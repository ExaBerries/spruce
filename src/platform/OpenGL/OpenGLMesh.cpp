#include "OpenGLMesh.h"
#include "../../graphics/Shader.h"

namespace spruce {
	OpenGLMesh::OpenGLMesh(int vertexCount, float* vertices, int indexCount, unsigned short* indices, Shader& shader) : Mesh(vertexCount, vertices, indexCount, indices, shader) {
		vao = 0;
		vbo = 0;
		ibo = 0;
	}

	OpenGLMesh::~OpenGLMesh() {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDeleteBuffers(1, &vbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glDeleteBuffers(1, &ibo);
		glDeleteVertexArrays(1, &vao);
	}

	void OpenGLMesh::toVRAM() {
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(float), vertices, GL_STATIC_DRAW);
		int stride = 0;
		for (int i = 0; i < shader.attributeCount; i++) {
			stride += shader.attributes[i].size;
		}
		stride *= sizeof(float);
		for (int j = 0; j < shader.attributeCount; j++) {
			glVertexAttribPointer(shader.getAttributeLocation(shader.attributes[j].name), shader.attributes[j].size, GL_FLOAT, GL_FALSE, stride, (void*) 0);
		}
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		if (indexCount > 0) {
			glGenBuffers(1, &ibo);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(unsigned short), indices, GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
	}

	void OpenGLMesh::bind() {
		glBindVertexArray(vao);
		if (ibo > 0) {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		}
	}

	void OpenGLMesh::unbind() {
		glBindVertexArray(0);
		if (ibo > 0) {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
	}
}
