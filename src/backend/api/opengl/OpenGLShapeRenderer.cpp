#include <backend/api/opengl/OpenGLShader.h>
#include <backend/api/opengl/OpenGLShapeRenderer.h>
#include <backend/api/opengl/platform.h>

namespace spruce {
	const string OpenGLShapeRenderer::vert  = "#version 330\nin vec3 a_pos;in vec4 a_color;uniform mat4 camera;out vec4 color;void main(){color=a_color;gl_Position=camera * vec4(a_pos,1.0);}";
	const string OpenGLShapeRenderer::frag = "#version 330\nin vec4 color;out vec4 fragColor;void main(){fragColor=color;}";
	const uint16 OpenGLShapeRenderer::MAX_VERTICES = 256;
	const uint16 OpenGLShapeRenderer::MAX_INDICES = 256;

	OpenGLShapeRenderer::OpenGLShapeRenderer() : attributes(2) {
		attributes[0] = VertexAttribute("a_pos", 3);
		attributes[1] = VertexAttribute("a_color", 4);
		shader = new OpenGLShader(vert, frag, attributes);
		shader->compile(nullptr);
		shader->registerUniform("camera", 1);
		lineVertexCount = 0;
		lineIndexCount = 0;
		filledVertexCount = 0;
		filledIndexCount = 0;
		lineVertices = new float[MAX_VERTICES];
		lineIndices = new uint16[MAX_INDICES];
		filledVertices = new float[MAX_VERTICES];
		filledIndices = new uint16[MAX_INDICES];

		uint16 stride = 0;
		for (int i = 0; i < shader->attributes.size; i++) {
			stride += shader->attributes[i].size;
		}
		stride *= sizeof(float);

		glGenVertexArrays(1, &lineVao);
		glBindVertexArray(lineVao);
		glGenBuffers(1, &lineVbo);
		glBindBuffer(GL_ARRAY_BUFFER, lineVbo);
		glBufferData(GL_ARRAY_BUFFER, MAX_VERTICES * sizeof(float), lineVertices, GL_DYNAMIC_DRAW);
		uint16 offset = 0;
		for (int j = 0; j < shader->attributes.size; j++) {
			glVertexAttribPointer(shader->getAttributeLocation(shader->attributes[j].name), shader->attributes[j].size, GL_FLOAT, GL_FALSE, stride, (void*) offset);
			offset += shader->attributes[j].size * sizeof(float);
		}
		glGenBuffers(1, &lineIbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, lineIbo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, MAX_INDICES * sizeof(uint16), lineIndices, GL_DYNAMIC_DRAW);

		glGenVertexArrays(1, &filledVao);
		glBindVertexArray(filledVao);
		glGenBuffers(1, &filledVbo);
		glBindBuffer(GL_ARRAY_BUFFER, filledVbo);
		glBufferData(GL_ARRAY_BUFFER, MAX_VERTICES * sizeof(float), filledVertices, GL_DYNAMIC_DRAW);
		offset = 0;
		for (int j = 0; j < shader->attributes.size; j++) {
			glVertexAttribPointer(shader->getAttributeLocation(shader->attributes[j].name), shader->attributes[j].size, GL_FLOAT, GL_FALSE, stride, (void*) offset);
			offset += shader->attributes[j].size * sizeof(float);
		}
		glGenBuffers(1, &filledIbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, filledIbo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, MAX_INDICES * sizeof(uint16), filledIndices, GL_DYNAMIC_DRAW);
	}

	OpenGLShapeRenderer::~OpenGLShapeRenderer() {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glDeleteBuffers(1, &lineVbo);
		glDeleteBuffers(1, &lineIbo);
		glDeleteVertexArrays(1, &lineVao);
		glDeleteBuffers(1, &filledVbo);
		glDeleteBuffers(1, &filledIbo);
		glDeleteVertexArrays(1, &filledVao);
		delete[] filledVertices;
		delete[] filledIndices;
		delete[] lineVertices;
		delete[] lineIndices;
		delete[] attributes;
		delete shader;
	}

	void OpenGLShapeRenderer::begin(Camera& camera) {
		this->camera = &(camera.combined);
		for (uint16 i = 0; i < MAX_VERTICES; i++) {
			lineVertices[i] = 0;
			filledVertices[i] = 0;
		}
		for (uint16 i = 0; i < MAX_INDICES; i++) {
			lineIndices[i] = 0;
			filledIndices[i] = 0;
		}
		lineVertexCount = 0;
		filledVertexCount = 0;
		lineIndexCount = 0;
		filledIndexCount = 0;
	}

	void OpenGLShapeRenderer::end() {
		shader->bind();
		shader->setUniform("camera", Shader::FRAGMENT, *camera);
		glBindVertexArray(lineVao);
		glBindBuffer(GL_ARRAY_BUFFER, lineVbo);
		glBufferSubData(GL_ARRAY_BUFFER, 0, MAX_VERTICES * sizeof(float), lineVertices);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, lineIbo);
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, MAX_INDICES * sizeof(uint16), lineIndices);
		for (int i = 0; i < shader->attributes.size; i++) {
			glEnableVertexAttribArray(shader->getAttributeLocation(shader->attributes[i].name));
		}
		glDrawElements(GL_LINES, lineIndexCount, GL_UNSIGNED_SHORT, 0);
		for (int i = 0; i < shader->attributes.size; i++) {
			glDisableVertexAttribArray(shader->getAttributeLocation(shader->attributes[i].name));
		}
		glBindVertexArray(filledVao);
		glBindBuffer(GL_ARRAY_BUFFER, filledVbo);
		glBufferSubData(GL_ARRAY_BUFFER, 0, MAX_VERTICES * sizeof(float), filledVertices);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, filledIbo);
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, MAX_INDICES * sizeof(uint16), filledIndices);
		for (int i = 0; i < shader->attributes.size; i++) {
			glEnableVertexAttribArray(shader->getAttributeLocation(shader->attributes[i].name));
		}
		glDrawElements(GL_TRIANGLES, filledIndexCount, GL_UNSIGNED_SHORT, 0);
		for (int i = 0; i < shader->attributes.size; i++) {
			glDisableVertexAttribArray(shader->getAttributeLocation(shader->attributes[i].name));
		}
		glBindVertexArray(0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void OpenGLShapeRenderer::line(vec3f a, vec3f b, color colora, color colorb) {
		uint16 i = lineIndexCount;
		lineVertices[lineVertexCount++] = a.x;
		lineVertices[lineVertexCount++] = a.y;
		lineVertices[lineVertexCount++] = a.z;
		lineVertices[lineVertexCount++] = colora.r;
		lineVertices[lineVertexCount++] = colora.g;
		lineVertices[lineVertexCount++] = colora.b;
		lineVertices[lineVertexCount++] = colora.a;
		lineIndices[i++] = lineIndexCount;
		lineVertices[lineVertexCount++] = b.x;
		lineVertices[lineVertexCount++] = b.y;
		lineVertices[lineVertexCount++] = b.z;
		lineVertices[lineVertexCount++] = colorb.r;
		lineVertices[lineVertexCount++] = colorb.g;
		lineVertices[lineVertexCount++] = colorb.b;
		lineVertices[lineVertexCount++] = colorb.a;
		lineIndices[i++] = lineIndexCount + 1;
		lineIndexCount = i;
	}

	void OpenGLShapeRenderer::rect(vec2f pos, vec2f size, color color) {
		vec2f halfSize = size / 2;
		uint16 firstIndex = filledVertexCount / 7;
		filledVertices[filledVertexCount++] = pos.x - halfSize.x;
		filledVertices[filledVertexCount++] = pos.y - halfSize.y;
		filledVertices[filledVertexCount++] = 0;
		filledVertices[filledVertexCount++] = color.r;
		filledVertices[filledVertexCount++] = color.g;
		filledVertices[filledVertexCount++] = color.b;
		filledVertices[filledVertexCount++] = color.a;
		filledVertices[filledVertexCount++] = pos.x + halfSize.x;
		filledVertices[filledVertexCount++] = pos.y - halfSize.y;
		filledVertices[filledVertexCount++] = 0;
		filledVertices[filledVertexCount++] = color.r;
		filledVertices[filledVertexCount++] = color.g;
		filledVertices[filledVertexCount++] = color.b;
		filledVertices[filledVertexCount++] = color.a;
		filledVertices[filledVertexCount++] = pos.x - halfSize.x;
		filledVertices[filledVertexCount++] = pos.y + halfSize.y;
		filledVertices[filledVertexCount++] = 0;
		filledVertices[filledVertexCount++] = color.r;
		filledVertices[filledVertexCount++] = color.g;
		filledVertices[filledVertexCount++] = color.b;
		filledVertices[filledVertexCount++] = color.a;
		filledVertices[filledVertexCount++] = pos.x + halfSize.x;
		filledVertices[filledVertexCount++] = pos.y + halfSize.y;
		filledVertices[filledVertexCount++] = 0;
		filledVertices[filledVertexCount++] = color.r;
		filledVertices[filledVertexCount++] = color.g;
		filledVertices[filledVertexCount++] = color.b;
		filledVertices[filledVertexCount++] = color.a;
		filledIndices[filledIndexCount++] = firstIndex + 0;
		filledIndices[filledIndexCount++] = firstIndex + 1;
		filledIndices[filledIndexCount++] = firstIndex + 2;
		filledIndices[filledIndexCount++] = firstIndex + 2;
		filledIndices[filledIndexCount++] = firstIndex + 1;
		filledIndices[filledIndexCount++] = firstIndex + 3;
	}
}
