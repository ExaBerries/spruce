#pragma once
#include <spruce.h>

using namespace spruce;

namespace sprucetest {
	class BasicRendererData {
		public:
			vec2i windowSize;
			mat4f cameraTrans;
			Mesh* cubeMesh = nullptr;
			mat4f worldTrans;
			sp::color color;

			BasicRendererData() = default;
			~BasicRendererData() = default;
	};
}
