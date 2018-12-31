#pragma once
#include <common.h>
#include <app/ApplicationFwd.h>
#include <graphics/Mesh.h>
#include <graphics/MeshAPIData.h>
#include <graphics/Texture.h>
#include <graphics/TextureAPIData.h>

namespace spruce {
	namespace graphics {
		class RendererAbstractor {
			public:
				RendererAbstractor() = default;
				virtual ~RendererAbstractor() = default;

				virtual std::any encodeBackend(Application& app) = 0;
				virtual void executeBackend(std::any data) = 0;

				virtual MeshAPIData* createMeshAPIData(Mesh& mesh) = 0;
				virtual TextureAPIData* createTextureAPIData(Texture& texture) = 0;
		};
	}

	using graphics::RendererAbstractor;
}
