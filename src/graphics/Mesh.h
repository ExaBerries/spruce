#pragma once
#include <common.h>
#include <graphics/Shader.h>

namespace spruce {
	class Mesh {
		public:
			buffer<float> vertices;
			buffer<uint16> indices;

			Mesh(buffer<float> vertices, buffer<uint16> indices);
			Mesh(const Mesh& mesh) = delete;
			virtual ~Mesh();

			virtual void toVRAM(Shader* shader) = 0;
			virtual void freeVRAM() = 0;
			void bind();
	};
}
