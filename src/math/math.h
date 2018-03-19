#pragma once
#include <math/random.h>
#include <math/quaternion.h>
#include <math/vec2i.h>
#include <math/vec2f.h>
#include <math/vec3d.h>
#include <math/vec3i.h>
#include <math/vec3f.h>
#include <math/vec3d.h>
#include <math/vec4f.h>
#include <math/mat4f.h>
#include <math.h>
#include <cmath>

namespace spruce {
	extern const float PI;

	float clamp(const float& value, float min, float max);
	float lerp(float a, float b, float alpha);
}
