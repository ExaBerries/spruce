#pragma once
#include <common.h>
#include <graphics/Mesh.h>
#include <graphics/Shader.h>
#include <graphics/MeshRenderer.h>
#include <graphics/Texture.h>

namespace spruce {
	class Backend {
		protected:
			uint16 windowWidth;
			uint16 windowHeight;
		public:
			virtual ~Backend();
			virtual void init() = 0;
			virtual void run() = 0;

			virtual Mesh* createMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices) = 0;
			virtual Shader* createShader(string& vertSource, string& fragSource, uint16 attributesCount, VertexAttribute* attributes) = 0;
			virtual MeshRenderer* createMeshRenderer() = 0;
			virtual Texture* createTexture(string& string) = 0;

			virtual bool keyPressed(uint16 code) = 0;

			uint16 getWindowWidth();
			uint16 getWindowHeight();
	};
}
