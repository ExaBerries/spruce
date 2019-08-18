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

				virtual std::any encodeBackend(void* encodeData) = 0;
				virtual void executeBackend(std::any executeData) = 0;

				virtual owner<MeshAPIData> createMeshAPIData(Mesh& mesh) = 0;
				virtual owner<TextureAPIData> createTextureAPIData(Texture& texture) = 0;
				virtual void setOrthographic(mat4f& matrix, float left, float right, float top, float bottom, float near, float far) = 0;
				virtual void setPerspective(mat4f& matrix, float near, float far, float fov, float aspectRatio) = 0;
		};
	}

	using graphics::RendererAbstractor;
}
