#pragma once
#include <common.h>
#include <graphics/Mesh.h>
#include <graphics/Shader.h>
#include <graphics/MeshRenderer.h>
#include <graphics/ShapeRenderer.h>
#include <graphics/Texture.h>
#include <input/input.h>

namespace spruce {
	class Backend {
		public:
			uint16 windowWidth;
			uint16 windowHeight;

			virtual ~Backend();
			virtual void init() = 0;
			virtual void run() = 0;

			virtual Mesh* createMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices) = 0;
			virtual Shader* createShader(string& vertSource, string& fragSource, uint16 attributesCount, VertexAttribute* attributes) = 0;
			virtual MeshRenderer* createMeshRenderer() = 0;
			virtual ShapeRenderer* createShapeRenderer() = 0;
			virtual Texture* createTexture(string& string) = 0;

			virtual void setBlend(bool value) = 0;
			virtual void setDepth(bool value) = 0;

			virtual string getGPUVendor() = 0;
			virtual uint16 getAPIVersionMajor() = 0;
			virtual uint16 getAPIVersionMinor() = 0;
			virtual string getAPIRendererName() = 0;

			virtual void setCursorMode(input::CursorMode mode) = 0;

			virtual bool keyPressed(uint16 code) = 0;
			virtual bool mouseButtonPressed(uint16 code) = 0;
			virtual vec2f mousePos() = 0;

			virtual uint16 codeFor(input::Key key) = 0;
			virtual uint16 codeFor(input::MouseButton button) = 0;
	};
}
