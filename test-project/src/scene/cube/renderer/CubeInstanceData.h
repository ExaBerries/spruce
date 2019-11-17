#pragma once
#include <spruce.h>

using namespace spruce;

namespace sprucetest {
	class CubeInstanceData {
		public:
			mat4f worldTrans;
			color color;

			CubeInstanceData();
			~CubeInstanceData();
	};
}
