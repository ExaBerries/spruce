#pragma once
#include <common.h>

namespace spruce {
	namespace graphics {
		class TextureAPIData {
			public:
				TextureAPIData() = default;
				TextureAPIData(const TextureAPIData&) = delete;
				TextureAPIData(TextureAPIData&&) = delete;
				virtual ~TextureAPIData() = default;

				TextureAPIData& operator=(const TextureAPIData&) = delete;
				TextureAPIData& operator=(TextureAPIData&&) noexcept = delete;
		};
	}

	using graphics::TextureAPIData;
}
