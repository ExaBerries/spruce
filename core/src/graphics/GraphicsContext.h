#pragma once
#include <common.h>
#include <graphics/CommandBuffer.h>
#include <graphics/Mesh.h>
#include <graphics/Shader.h>
#include <graphics/Primitive.h>

namespace spruce {
	namespace graphics {
		class GraphicsContext {
			public:
				CommandBuffer cmdBuffer;

				GraphicsContext();
				virtual ~GraphicsContext();

				void render(Mesh* mesh, Shader* shader, Primitive primitive);
		};
	}
}
