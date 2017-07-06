#include "Game.h"

namespace spruce {
	Game::Game() {
		window = 0;
		screen = 0;
	}

	Game::~Game() {
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

	void Game::init() {
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

	void Game::run() {
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
			if (screen != NULL) {
				screen->update(delta);
				screen->render(delta);
			}
			lastTime = newTime;
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void Game::setScreen(graphics::Screen* screen) {
		this->screen = screen;
	}
}
