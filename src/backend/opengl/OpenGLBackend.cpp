#include <backend/opengl/OpenGLBackend.h>
#include <backend/opengl/OpenGLMesh.h>
#include <backend/opengl/OpenGLMeshRenderer.h>
#include <backend/opengl/OpenGLShader.h>
#include <backend/opengl/OpenGLTexture.h>
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

	static void joystickCallback(int32 joystick, int32 event) {
		if (event == GLFW_CONNECTED) {

		} else if (event == GLFW_DISCONNECTED) {

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
		glfwSetJoystickCallback(joystickCallback);
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
				string string = "OpenGL Error=";
				string += std::to_string(error);
				log(string);
			}
			int32 tmpWidth = 0;
			int32 tmpHeight = 0;
			glfwGetWindowSize(window, &tmpWidth, &tmpHeight);
			this->windowWidth = tmpWidth;
			this->windowHeight = tmpHeight;
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

	string OpenGLBackend::getGPUVendor() {
		return string(reinterpret_cast<const char*>(glGetString(GL_VENDOR)));
	}

	uint16 OpenGLBackend::getAPIVersionMajor() {
		int32 major = 0;
		glGetIntegerv(GL_MAJOR_VERSION, &major);
		return major;
	}

	uint16 OpenGLBackend::getAPIVersionMinor() {
		int32 minor = 0;
		glGetIntegerv(GL_MAJOR_VERSION, &minor);
		return minor;
	}

	string OpenGLBackend::getAPIRendererName() {
		return string(reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
	}

	void OpenGLBackend::setCursorMode(input::CursorMode mode) {
		uint32 glfwMode = GLFW_CURSOR_NORMAL;
		switch (mode) {
			case input::HIDDEN:
				glfwMode = GLFW_CURSOR_HIDDEN;
				break;
			case input::DISABLED:
				glfwMode = GLFW_CURSOR_DISABLED;
				break;
			default:
				break;
		}
		glfwSetInputMode(window, GLFW_CURSOR, glfwMode);
	}

	bool OpenGLBackend::keyPressed(uint16 code) {
		return (glfwGetKey(window, code) == GLFW_PRESS);
	}

	bool OpenGLBackend::mouseButtonPressed(uint16 code) {
		return (glfwGetMouseButton(window, code) == GLFW_PRESS);
	}

	vec2f OpenGLBackend::mousePos() {
		double x = 0.0;
		double y = 0.0;
		glfwGetCursorPos(window, &x, &y);
		return vec2f(x, y);
	}

	uint16 OpenGLBackend::codeFor(input::Key key) {
		uint16 code = 0;
		switch (key) {
			case input::A:
				code = GLFW_KEY_A;
				break;
			case input::B:
				code = GLFW_KEY_B;
				break;
			case input::C:
				code = GLFW_KEY_C;
				break;
			case input::D:
				code = GLFW_KEY_D;
				break;
			case input::E:
				code = GLFW_KEY_E;
				break;
			case input::F:
				code = GLFW_KEY_F;
				break;
			case input::G:
				code = GLFW_KEY_G;
				break;
			case input::H:
				code = GLFW_KEY_H;
				break;
			case input::I:
				code = GLFW_KEY_I;
				break;
			case input::J:
				code = GLFW_KEY_J;
				break;
			case input::K:
				code = GLFW_KEY_K;
				break;
			case input::L:
				code = GLFW_KEY_L;
				break;
			case input::M:
				code = GLFW_KEY_M;
				break;
			case input::N:
				code = GLFW_KEY_N;
				break;
			case input::O:
				code = GLFW_KEY_O;
				break;
			case input::P:
				code = GLFW_KEY_P;
				break;
			case input::Q:
				code = GLFW_KEY_Q;
				break;
			case input::R:
				code = GLFW_KEY_R;
				break;
			case input::S:
				code = GLFW_KEY_S;
				break;
			case input::T:
				code = GLFW_KEY_T;
				break;
			case input::U:
				code = GLFW_KEY_U;
				break;
			case input::V:
				code = GLFW_KEY_V;
				break;
			case input::W:
				code = GLFW_KEY_W;
				break;
			case input::X:
				code = GLFW_KEY_X;
				break;
			case input::Y:
				code = GLFW_KEY_Y;
				break;
			case input::Z:
				code = GLFW_KEY_Z;
				break;
			case input::ZERO:
				code = GLFW_KEY_0;
				break;
			case input::ONE:
				code = GLFW_KEY_1;
				break;
			case input::TWO:
				code = GLFW_KEY_2;
				break;
			case input::THREE:
				 code = GLFW_KEY_3;
				 break;
			case input::FOUR:
				code = GLFW_KEY_4;
				break;
			case input::FIVE:
				code = GLFW_KEY_5;
				break;
			case input::SIX:
				code = GLFW_KEY_6;
				break;
			case input::SEVEN:
				code = GLFW_KEY_7;
				break;
			case input::EIGHT:
				code = GLFW_KEY_8;
				break;
			case input::NINE:
				code = GLFW_KEY_9;
				break;
			case input::ENTER:
				code = GLFW_KEY_ENTER;
				break;
			case input::ESCAPE:
				code = GLFW_KEY_ESCAPE;
				break;
			case input::DELETE:
				code = GLFW_KEY_DELETE;
				break;
			case input::TAB:
				code = GLFW_KEY_TAB;
				break;
			case input::SPACE:
				code = GLFW_KEY_SPACE;
				break;
			case input::SHIFT_LEFT:
				code = GLFW_KEY_LEFT_SHIFT;
				break;
			case input::SHIFT_RIGHT:
				code = GLFW_KEY_RIGHT_SHIFT;
				break;
			case input::CONTROL_LEFT:
				code = GLFW_KEY_LEFT_CONTROL;
				break;
			case input::CONTROL_RIGHT:
				code = GLFW_KEY_RIGHT_CONTROL;
				break;
			default:
				code = 0;
				break;
		}
		return code;
	}

	uint16 OpenGLBackend::codeFor(input::MouseButton button) {
		uint16 code = 0;
		switch (button) {
			case input::LEFT:
				code = GLFW_MOUSE_BUTTON_LEFT;
				break;
			case input::CENTER:
				code = GLFW_MOUSE_BUTTON_MIDDLE;
				break;
			case input::RIGHT:
				code = GLFW_MOUSE_BUTTON_RIGHT;
				break;
			default:
				code = 0;
				break;
		}
		return 0;
	}
}
