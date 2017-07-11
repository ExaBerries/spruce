#pragma once
#include "../Backend.h"
#include <GLFW/glfw3.h>
#include "../../graphics/Screen.h"
#include "../../log.h"

namespace spruce {
	namespace app {
		extern graphics::Screen* screen;
	}

	class OpenGLBackend : public Backend {
		public:
			GLFWwindow* window;

			OpenGLBackend();
			virtual ~OpenGLBackend();

			void init();
			void run();

			Mesh* createMesh(int vertexCount, float* vertices, int indexCount, unsigned short* indices, Shader& shader);
			Shader* createShader(char* vertSource, char* fragSource, int attributesCount, VertexAttribute* attributes);
			MeshRenderer* createMeshRenderer();
			// TODO virtual Texture* createTexture();

			int getWindowWidth();
			int getWindowHeight();
	};
}
