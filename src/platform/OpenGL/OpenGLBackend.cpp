#include "OpenGLBackend.h"
#include "OpenGLMesh.h"
#include "OpenGLShader.h"
#include "OpenGLMeshRenderer.h"

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
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
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
			}
			lastTime = newTime;
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	Mesh* OpenGLBackend::createMesh(int vertexCount, float* vertices, int indexCount, unsigned short* indices, Shader& shader) {
		return new OpenGLMesh(vertexCount, vertices, indexCount, indices, shader);
	}

	Shader* OpenGLBackend::createShader(char* vertSource, char* fragSource, int attributesCount, VertexAttribute* attributes) {
		return new OpenGLShader(vertSource, fragSource, attributesCount, attributes);
	}

	MeshRenderer* OpenGLBackend::createMeshRenderer() {
		return new OpenGLMeshRenderer();
	}

	// TODO Texture* createTexture() {

	int OpenGLBackend::getWindowWidth() {
		return 0;
	}

	int OpenGLBackend::getWindowHeight() {
		return 0;
	}
}
