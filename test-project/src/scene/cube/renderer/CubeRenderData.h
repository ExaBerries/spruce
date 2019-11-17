#pragma once
#include <scene/cube/renderer/CubeInstanceData.h>
#include <spruce.h>

using namespace spruce;

namespace sprucetest {
	class CubeRenderData {
		public:
			vec2i viewport;
			Mesh* cube = nullptr;
			Mesh* plane = nullptr;
			std::vector<CubeInstanceData> cubeInstances;
			vec3f sunDir;
			mat4f cameraTrans;
			mat4f planeTrans;
			color planeCol;
			Mesh* screenQuad = nullptr;

			CubeRenderData() = default;
			~CubeRenderData() = default;
	};
}
