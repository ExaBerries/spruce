#include <platform/OpenGL/OpenGLBackend.h>
#include <platform/OpenGL/OpenGLMesh.h>
#include <platform/OpenGL/OpenGLShader.h>
#include <platform/OpenGL/OpenGLMeshRenderer.h>
#include <platform/OpenGL/OpenGLTexture.h>

#include <util/image.h>

namespace spruce {
	OpenGLBackend::OpenGLBackend() {
		window = 0;
	}

	OpenGLBackend::~OpenGLBackend() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	static void errorCallback(int error, const char* description) {
		std::string string = "glfwError ";
		string += error;
		string += description;
		log(string);
	}

	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
			 glfwSetWindowShouldClose(window, GLFW_TRUE);
		}
	}

	void OpenGLBackend::init() {
		glfwSetErrorCallback(errorCallback);
		if (!glfwInit()) {
			log("glfw could not init");
		}
		glfwDefaultWindowHints();
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		window = glfwCreateWindow(1280, 720, "test", NULL, NULL);
		if (window == NULL) {
			log("window == NULL");
		}
		glfwSetKeyCallback(window, keyCallback);
		glfwMakeContextCurrent(window);
		glfwSwapInterval(1);
		glfwShowWindow(window);
	}

	void OpenGLBackend::run() {
		double lastTime = glfwGetTime();
		while (!glfwWindowShouldClose(window)) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			int error = glGetError();
			if (error != GL_NO_ERROR) {
				std::string string = "OpenGL Error=";
				string += std::to_string(error);
				log(string);
			}
			double newTime = glfwGetTime();
			double delta = newTime - lastTime;
			if (app::screen != NULL) {
				app::screen->update(delta);
				app::screen->render(delta);
				int tmpWidth = 0;
				int tmpHeight = 0;
				glfwGetWindowSize(window, &tmpWidth, &tmpHeight);
				this->windowWidth = tmpWidth;
				this->windowHeight = tmpHeight;
			}
			lastTime = newTime;
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}

	Mesh* OpenGLBackend::createMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices) {
		return new OpenGLMesh(vertexCount, vertices, indexCount, indices);
	}

	Shader* OpenGLBackend::createShader(string& vertSource, string& fragSource, uint16 attributesCount, VertexAttribute* attributes) {
		return new OpenGLShader(vertSource, fragSource, attributesCount, attributes);
	}

	MeshRenderer* OpenGLBackend::createMeshRenderer() {
		return new OpenGLMeshRenderer();
	}

	Texture* OpenGLBackend::createTexture(string& path) {
		uint16 width = 0;
		uint16 height = 0;
		uint16 bitsPerPixel = 0;
		uint8* data = util::loadImage(path, width, height, bitsPerPixel);
		return new OpenGLTexture(data, width, height, bitsPerPixel);
	}
}
