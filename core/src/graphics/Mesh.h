#pragma once
#include <common.h>
#include <graphics/MeshAPIData.h>
#include <graphics/renderer/RendererAbstractorFwd.h>

namespace spruce {
	namespace graphics {
		class Mesh {
			public:
				buffer<float> vertices;
				buffer<uint16> indices;
				owner<MeshAPIData> apiData;

				Mesh(buffer<float>& vertices, buffer<uint16>& indices);
				Mesh(const Mesh&) = delete;
				Mesh(Mesh&&) noexcept = delete;
				~Mesh();

				void toVRAM(RendererAbstractor* renderer) noexcept;
				void freeVRAM() noexcept;

				Mesh& operator=(const Mesh&) = delete;
				Mesh& operator=(Mesh&&) noexcept = delete;
		};
	}

	using graphics::Mesh;
}
