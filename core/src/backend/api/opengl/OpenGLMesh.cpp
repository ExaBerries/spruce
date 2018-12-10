#include <backend/api/opengl/OpenGLMesh.h>
#include <graphics/Shader.h>
#include <backend/api/opengl/platform.h>

namespace spruce {
	OpenGLMesh::OpenGLMesh(buffer<float> vertices, buffer<uint16> indices) : Mesh(vertices, indices) {
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
			glBufferData(GL_ARRAY_BUFFER, vertices.size * sizeof(float), vertices.data, GL_DYNAMIC_DRAW);
			bufferVertexCount = vertices.size;
		} else {
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			if (bufferVertexCount == vertices.size) {
				glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size * sizeof(float), vertices.data);
			} else {
				glDeleteBuffers(1, &vbo);
				glGenBuffers(1, &vbo);
				glBindBuffer(GL_ARRAY_BUFFER, vbo);
				glBufferData(GL_ARRAY_BUFFER, vertices.size * sizeof(float), vertices.data, GL_DYNAMIC_DRAW);
				bufferVertexCount = vertices.size;
			}
		}
		uint16 stride = 0;
		for (uint32 i = 0; i < shader->attributes.size; i++) {
			stride += shader->attributes[i].size;
		}
		stride *= sizeof(float);
		uint64 offset = 0;
		for (uint32 j = 0; j < shader->attributes.size; j++) {
			glVertexAttribPointer(shader->getAttributeLocation(shader->attributes[j].name), shader->attributes[j].size, GL_FLOAT, GL_FALSE, stride, (void*) offset);
			offset += shader->attributes[j].size * sizeof(float);
		}
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		if (indices.size > 0) {
			if (ibo == 0) {
				glGenBuffers(1, &ibo);
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
				glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size * sizeof(uint16), indices.data, GL_DYNAMIC_DRAW);
				bufferIndexCount = indices.size;
			} else {
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
				if (bufferIndexCount == indices.size) {
					glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, indices.size * sizeof(uint16), indices.data);
				} else {
					glDeleteBuffers(1, &ibo);
					glGenBuffers(1, &ibo);
					glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
					glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size * sizeof(uint16), indices.data, GL_DYNAMIC_DRAW);
					bufferIndexCount = indices.size;
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
