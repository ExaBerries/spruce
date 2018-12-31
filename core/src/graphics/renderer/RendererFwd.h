#pragma once
#include <common.h>
#include <app/API.h>

namespace spruce {
	namespace graphics {
		template <typename AppT, typename DataT, enum app::API api>
		class Renderer;
	}

	using graphics::Renderer;
}
