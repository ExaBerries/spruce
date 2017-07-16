#pragma once
#include <common.h>
#include <platform/Backend.h>
#include <GLFW/glfw3.h>
#include <graphics/Screen.h>
#include <log.h>

namespace spruce {
	namespace app {
		extern graphics::Screen* screen;
	}

	class OpenGLBackend : public Backend {
		public:
			GLFWwindow* window;

			OpenGLBackend();
			~OpenGLBackend();

			void init();
			void run();

			Mesh* createMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices);
			Shader* createShader(string& vertSource, string& fragSource, uint16 attributesCount, VertexAttribute* attributes);
			MeshRenderer* createMeshRenderer();
			Texture* createTexture(string& path);

			int getWindowWidth();
			int getWindowHeight();
	};
}
