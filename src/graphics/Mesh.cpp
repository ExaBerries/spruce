#include "Mesh.h"

namespace spruce {
	Mesh::Mesh(int vertexCount, float* vertices, int indexCount, short* indices) {
		vao = 0;
		vbo = 0;
		ibo = 0;
		this->vertexCount = vertexCount;
		this->vertices = vertices;
		this->indexCount = indexCount;
		this->indices = indices;
	}

	Mesh::~Mesh() {
	}

	void Mesh::toVRAM() {
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		/*
		for (VertexAttribute attribute : shader.getVertexAttributes()) {
			glVertexAttribPointer(shader.getAttributeLocation(attribute.getName()), 3, GL_FLOAT, false, 0, 0);
		}
		*/
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
}
