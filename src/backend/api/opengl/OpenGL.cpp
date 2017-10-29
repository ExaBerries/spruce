#include <backend/api/opengl/OpenGL.h>
#include <backend/api/opengl/OpenGLMesh.h>
#include <backend/api/opengl/OpenGLMeshRenderer.h>
#include <backend/api/opengl/OpenGLShader.h>
#include <backend/api/opengl/OpenGLShapeRenderer.h>
#include <backend/api/opengl/OpenGLTexture.h>
#include <io/image.h>
#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/gl3.h>
#endif

namespace spruce {
	OpenGL::OpenGL(Window* window) : RenderAPI(window) {
	}

	OpenGL::~OpenGL() {
		window->close();
	}

	void OpenGL::init() {
		makeContextCurrent(window);
		swapInterval(window, 1);
		window->setVisible(true);
	}

	void OpenGL::updateStart() {
		glViewport(0, 0, window->width, window->height);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGL::updateEnd() {
		swapBuffers(window);
	}

	Mesh* OpenGL::createMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices) {
		return new OpenGLMesh(vertexCount, vertices, indexCount, indices);
	}

	Shader* OpenGL::createShader(string& vertSource, string& fragSource, uint16 attributesCount, VertexAttribute* attributes) {
		return new OpenGLShader(vertSource, fragSource, attributesCount, attributes);
	}

	MeshRenderer* OpenGL::createMeshRenderer() {
		return new OpenGLMeshRenderer();
	}

	ShapeRenderer* OpenGL::createShapeRenderer() {
		return new OpenGLShapeRenderer();
	}

	Texture* OpenGL::createTexture(string& path) {
		uint16 width = 0;
		uint16 height = 0;
		uint16 bitsPerPixel = 0;
		uint8* data = io::loadImage(path, width, height, bitsPerPixel);
		return new OpenGLTexture(data, width, height, bitsPerPixel);
	}

	void OpenGL::setBlend(bool value) {
		if (value) {
			glEnable(GL_BLEND);
			glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE);
		} else {
			glDisable(GL_BLEND);
		}
	}

	void OpenGL::setDepth(bool value) {
		if (value) {
			glEnable(GL_DEPTH_TEST);
		} else {
			glDisable(GL_DEPTH_TEST);
		}
	}

	string OpenGL::getGPUVendor() {
		return string(reinterpret_cast<const char*>(glGetString(GL_VENDOR)));
	}

	uint16 OpenGL::getAPIVersionMajor() {
		int32 major = 0;
		glGetIntegerv(GL_MAJOR_VERSION, &major);
		return major;
	}

	uint16 OpenGL::getAPIVersionMinor() {
		int32 minor = 0;
		glGetIntegerv(GL_MINOR_VERSION, &minor);
		return minor;
	}

	string OpenGL::getAPIRendererName() {
		return string(reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
	}
}
