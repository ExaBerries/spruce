#pragma once

namespace spruce {
	class Shader;

	class Mesh {
		public:
			int vertexCount;
			float* vertices;
			int indexCount;
			unsigned short* indices;
			Shader& shader;

			Mesh(int vertexCount, float* vertices, int indexCount, unsigned short* indices, Shader& shader);
			virtual ~Mesh();
			virtual void toVRAM() = 0;
			virtual void bind() = 0;
			virtual void unbind() = 0;
	};
}
