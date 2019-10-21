#pragma once
#ifdef __APPLE__
#include <common.h>
#include <graphics/renderer/Renderer.h>
#include <graphics/renderer/api/metal/MetalContext.h>
#include <app/Application.h>

namespace spruce {
	namespace graphics {
		template <typename EncodeT, typename ExecuteT>
		class MetalRenderer : public Renderer<EncodeT, ExecuteT, app::METAL> {
			public:
				MetalContext& context;

				explicit MetalRenderer(Application& app);
				MetalRenderer(const MetalRenderer&) = delete;
				MetalRenderer(MetalRenderer&&) noexcept = delete;
				~MetalRenderer() = default;

				void setOrthographic(mat4f& matrix, float left, float right, float top, float bottom, float near, float far) noexcept override;
				void setPerspective(mat4f& matrix, float near, float far, float fov, float aspectRatio) noexcept override;

				MetalRenderer& operator=(const MetalRenderer&) = delete;
				MetalRenderer& operator=(MetalRenderer&&) noexcept = delete;
		};

		template <typename EncodeT, typename ExecuteT>
		MetalRenderer<EncodeT, ExecuteT>::MetalRenderer(Application& app) : context(*static_cast<MetalContext*>(app.engine.apiContext)) {
		}

		template <typename EncodeT, typename ExecuteT>
		void MetalRenderer<EncodeT, ExecuteT>::setOrthographic(mat4f& matrix, float left, float right, float top, float bottom, float near, float far) noexcept {
			matrix.values[0] = 2.0f / (right - left);
			matrix.values[1] = 0.0f;
			matrix.values[2] = 0.0f;
			matrix.values[3] = (left + right) / (left - right);
			matrix.values[4] = 0.0f;
			matrix.values[5] = -2.0f / (top - bottom);
			matrix.values[6] = 0.0f;
			matrix.values[7] = (bottom + top) / (bottom - top);
			matrix.values[8] = 0.0f;
			matrix.values[9] = 0.0f;
			matrix.values[10] = -1.0f / (far - near);
			matrix.values[11] = near / (near - far);
			matrix.values[12] = 0.0f;
			matrix.values[13] = 0.0f;
			matrix.values[14] = 0.0f;
			matrix.values[15] = 1.0f;
		}

		template <typename EncodeT, typename ExecuteT>
		void MetalRenderer<EncodeT, ExecuteT>::setPerspective(mat4f& matrix, float near, float far, float fov, float aspectRatio) noexcept {
			float size = 1.0f / tan(fov / 2.0f);
			matrix.values[0] = size / aspectRatio;
			matrix.values[1] = 0.0f;
			matrix.values[2] = 0.0f;
			matrix.values[3] = 0.0f;
			matrix.values[4] = 0.0f;
			matrix.values[5] = size;
			matrix.values[6] = 0.0f;
			matrix.values[7] = 0.0f;
			matrix.values[8] = 0.0f;
			matrix.values[9] = 0.0f;
			matrix.values[10] = far / (near - far);
			matrix.values[11] = (far * near) / (near - far);
			matrix.values[12] = 0.0f;
			matrix.values[13] = 0.0f;
			matrix.values[14] = -1.0f;
			matrix.values[15] = 0.0f;
		}
	}

	using graphics::MetalRenderer;
}
#endif
