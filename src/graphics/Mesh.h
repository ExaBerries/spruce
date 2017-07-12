#pragma once
#include <common.h>

namespace spruce {
	class Shader;

	class Mesh {
		public:
			uint16 vertexCount;
			float* vertices;
			uint16 indexCount;
			uint16* indices;
			Shader* shader;

			virtual ~Mesh();
			virtual void toVRAM() = 0;
			virtual void bind() = 0;
			virtual void unbind() = 0;
	};
}
