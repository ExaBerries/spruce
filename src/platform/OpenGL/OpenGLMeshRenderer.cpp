#include "OpenGLMeshRenderer.h"
#include <GLFW/glfw3.h>
#include "../../graphics/Shader.h"
#include "../../log.h"

namespace spruce {
	OpenGLMeshRenderer::OpenGLMeshRenderer() {
	}

	OpenGLMeshRenderer::~OpenGLMeshRenderer() {
	}

	void OpenGLMeshRenderer::render(Mesh& mesh, Shader& shader) {
		mesh.bind();
		for (int i = 0; i < shader.attributeCount; i++) {
			glEnableVertexAttribArray(shader.getAttributeLocation(shader.attributes[i].name));
		}
		//shader.renderCallback();
		if (mesh.indices > 0) {
			glDrawElements(GL_TRIANGLES, mesh.indexCount, GL_UNSIGNED_SHORT, 0);
		} else {
			glDrawArrays(GL_POINTS, 0, mesh.indexCount);
		}
		for (int i = 0; i < shader.attributeCount; i++) {
			glDisableVertexAttribArray(shader.getAttributeLocation(shader.attributes[i].name));
		}
		mesh.unbind();
	}
}
