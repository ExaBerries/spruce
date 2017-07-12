#pragma once
#include <common.h>
#include <graphics/Screen.h>
#include <graphics/Mesh.h>
#include <graphics/Shader.h>
#include <graphics/MeshRenderer.h>
#include <graphics/Camera.h>

namespace spruce {
	namespace graphics {
		Mesh* createMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices, Shader* shader);
		Shader* createShader(char* vertSource, char* fragSource, uint16 attributesCount, VertexAttribute* attributes);
		MeshRenderer* createMeshRenderer();

		int getWidth();
		int getHeight();
	}
}
