#pragma once
#include <common.h>

namespace spruce {
	namespace graphics {
		class MeshAPIData {
			public:
				MeshAPIData() = default;
				MeshAPIData(const MeshAPIData&) = delete;
				MeshAPIData(MeshAPIData&&) noexcept = delete;
				virtual ~MeshAPIData() = default;

				MeshAPIData& operator=(const MeshAPIData&) = delete;
				MeshAPIData& operator=(MeshAPIData&&) noexcept = delete;
		};
	}

	using graphics::MeshAPIData;
}
