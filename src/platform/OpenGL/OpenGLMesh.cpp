#include <platform/OpenGL/OpenGLMesh.h>
#include <graphics/Shader.h>
#include <log.h>

namespace spruce {
	OpenGLMesh::OpenGLMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices, Shader* shader) {
		vao = 0;
		vbo = 0;
		ibo = 0;
		this->vertexCount = vertexCount;
		this->vertices = vertices;
		this->indexCount = indexCount;
		this->indices = indices;
		this->shader = shader;
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
		unsigned int stride = 0;
		for (int i = 0; i < shader->attributeCount; i++) {
			stride += shader->attributes[i].size;
		}
		stride *= sizeof(float);
		unsigned int offset = 0;
		for (int j = 0; j < shader->attributeCount; j++) {
			glVertexAttribPointer(shader->getAttributeLocation(shader->attributes[j].name), shader->attributes[j].size, GL_FLOAT, GL_FALSE, stride, (void*) offset);
			offset += shader->attributes[j].size * sizeof(float);
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
