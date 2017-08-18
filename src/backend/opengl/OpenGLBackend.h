#pragma once
#include <backend/Backend.h>
#include <common.h>
#include <GLFW/glfw3.h>
#include <graphics/Screen.h>

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

			string getGPUVendor();
			uint16 getAPIVersionMajor();
			uint16 getAPIVersionMinor();
			string getAPIRendererName();

			bool keyPressed(uint16 code);
			bool mouseButtonPressed(uint16 code);

			uint16 codeFor(input::Key key);
			uint16 codeFor(input::MouseButton button);
	};
}
