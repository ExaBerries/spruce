#include <backend/api/opengl/OpenGLMesh.h>
#include <graphics/Shader.h>
#include <backend/api/opengl/platform.h>

namespace spruce {
	OpenGLMesh::OpenGLMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices) : Mesh(vertexCount, vertices, indexCount, indices) {
		vao = 0;
		vbo = 0;
		ibo = 0;
		bufferVertexCount = 0;
		bufferIndexCount = 0;
	}

	OpenGLMesh::~OpenGLMesh() {
		freeVRAM();
	}

	void OpenGLMesh::toVRAM(Shader* shader) {
		if (vao == 0) {
			glGenVertexArrays(1, &vao);
		}
		glBindVertexArray(vao);
		if (vbo == 0) {
			glGenBuffers(1, &vbo);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(float), vertices, GL_DYNAMIC_DRAW);
			bufferVertexCount = vertexCount;
		} else {
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			if (bufferVertexCount == vertexCount) {
				glBufferSubData(GL_ARRAY_BUFFER, 0, vertexCount * sizeof(float), vertices);
			} else {
				glDeleteBuffers(1, &vbo);
				glGenBuffers(1, &vbo);
				glBindBuffer(GL_ARRAY_BUFFER, vbo);
				glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(float), vertices, GL_DYNAMIC_DRAW);
				bufferVertexCount = vertexCount;
			}
		}
		uint16 stride = 0;
		for (int i = 0; i < shader->attributeCount; i++) {
			stride += shader->attributes[i].size;
		}
		stride *= sizeof(float);
		uint16 offset = 0;
		for (int j = 0; j < shader->attributeCount; j++) {
			glVertexAttribPointer(shader->getAttributeLocation(shader->attributes[j].name), shader->attributes[j].size, GL_FLOAT, GL_FALSE, stride, (void*) offset);
			offset += shader->attributes[j].size * sizeof(float);
		}
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		if (indexCount > 0) {
			if (ibo == 0) {
				glGenBuffers(1, &ibo);
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
				glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(uint16), indices, GL_DYNAMIC_DRAW);
				bufferIndexCount = indexCount;
			} else {
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
				if (bufferIndexCount == indexCount) {
					glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, indexCount * sizeof(uint16), indices);
				} else {
					glDeleteBuffers(1, &ibo);
					glGenBuffers(1, &ibo);
					glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
					glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(uint16), indices, GL_DYNAMIC_DRAW);
					bufferIndexCount = indexCount;
				}
			}
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
	}

	void OpenGLMesh::freeVRAM() {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDeleteBuffers(1, &vbo);
		if (ibo > 0) {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			glDeleteBuffers(1, &ibo);
		}
		glDeleteVertexArrays(1, &vao);
	}
}
