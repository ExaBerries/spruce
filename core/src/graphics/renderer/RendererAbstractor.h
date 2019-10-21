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
				RendererAbstractor(const RendererAbstractor&) = default;
				RendererAbstractor(RendererAbstractor&&) noexcept = default;
				virtual ~RendererAbstractor() = default;

				[[nodiscard]] virtual std::any encodeBackend(void* encodeData) noexcept = 0;
				virtual void executeBackend(std::any executeData) noexcept = 0;

				[[nodiscard]] virtual owner<MeshAPIData> createMeshAPIData(Mesh& mesh) noexcept = 0;
				[[nodiscard]] virtual owner<TextureAPIData> createTextureAPIData(Texture& texture) noexcept = 0;
				virtual void setOrthographic(mat4f& matrix, float left, float right, float top, float bottom, float near, float far) noexcept = 0;
				virtual void setPerspective(mat4f& matrix, float near, float far, float fov, float aspectRatio) noexcept = 0;

				RendererAbstractor& operator=(const RendererAbstractor&) = default;
				RendererAbstractor& operator=(RendererAbstractor&&) noexcept = default;
		};
	}

	using graphics::RendererAbstractor;
}
