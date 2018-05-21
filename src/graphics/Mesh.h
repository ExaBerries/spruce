#pragma once
#include <common.h>
#include <graphics/Shader.h>

namespace spruce {
	class Mesh {
		public:
			uint16 vertexCount;
			float* vertices;
			uint16 indexCount;
			uint16* indices;

			Mesh(const Mesh& mesh);
			Mesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices);
			virtual ~Mesh();

			virtual void toVRAM(Shader* shader) = 0;
			virtual void freeVRAM() = 0;
			void bind();
	};
}
