#include <backend/api/opengl/OpenGLMeshRenderer.h>
#include <backend/api/opengl/platform.h>
#include <graphics/Shader.h>
#include <log.h>

namespace spruce {
	OpenGLMeshRenderer::OpenGLMeshRenderer() {
	}

	OpenGLMeshRenderer::~OpenGLMeshRenderer() {
	}

	void OpenGLMeshRenderer::render(Mesh* mesh, Shader* shader) {
		glEnable(GL_DEPTH_TEST);
		mesh->bind();
		for (int i = 0; i < shader->attributeCount; i++) {
			glEnableVertexAttribArray(shader->getAttributeLocation(shader->attributes[i].name));
		}
		//shader->renderCallback();
		if (mesh->indices > 0) {
			glDrawElements(GL_TRIANGLES, mesh->indexCount, GL_UNSIGNED_SHORT, 0);
		} else {
			glDrawArrays(GL_TRIANGLES, 0, mesh->vertexCount);
		}
		for (int i = 0; i < shader->attributeCount; i++) {
			glDisableVertexAttribArray(shader->getAttributeLocation(shader->attributes[i].name));
		}
		mesh->unbind();
	}
}
