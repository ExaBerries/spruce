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
			ShapeRenderer* createShapeRenderer();
			Texture* createTexture(string& path);

			void setBlend(bool value);
			void setDepth(bool value);

			string getGPUVendor();
			uint16 getAPIVersionMajor();
			uint16 getAPIVersionMinor();
			string getAPIRendererName();

			void setCursorMode(input::CursorMode mode);

			bool keyPressed(uint16 code);
			bool mouseButtonPressed(uint16 code);
			vec2f mousePos();

			uint16 codeFor(input::Key key);
			uint16 codeFor(input::MouseButton button);
	};
}
