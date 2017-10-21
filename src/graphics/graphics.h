#pragma once
#include <common.h>
#include <graphics/Screen.h>
#include <graphics/Mesh.h>
#include <graphics/Shader.h>
#include <graphics/MeshRenderer.h>
#include <graphics/ShapeRenderer.h>
#include <graphics/Camera.h>
#include <graphics/PerspectiveCamera.h>
#include <graphics/OrthographicCamera.h>
#include <graphics/Texture.h>
#include <graphics/color.h>

namespace spruce {
	namespace graphics {
		Mesh* createMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices);
		Shader* createShader(string& vertSource, string& fragSource, uint16 attributesCount, VertexAttribute* attributes);
		MeshRenderer* createMeshRenderer();
		ShapeRenderer* createShapeRenderer();
		PerspectiveCamera* createPerspectiveCamera(float viewportWidth, float viewportHeight, float fieldOfView, float near, float far, vec3f& up, vec3f& dir);
		OrthographicCamera* createOrthographicCamera(float viewportWidth, float viewportHeight, float near, float far, vec3f& up);
		Texture* createTexture(string& path);

		void setBlend(bool value);
		void setDepth(bool value);

		int getWidth();
		int getHeight();

		string getGPUVendor();
		uint16 getAPIVersionMajor();
		uint16 getAPIVersionMinor();
		string getAPIRendererName();
	}
}
