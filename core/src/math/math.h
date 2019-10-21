#pragma once
#include <math/mat/mat4f.h>
#include <math/random.h>
#include <math/quaternion.h>
#include <math/vec/vec2i.h>
#include <math/vec/vec2f.h>
#include <math/vec/vec3d.h>
#include <math/vec/vec3i.h>
#include <math/vec/vec3f.h>
#include <math/vec/vec3d.h>
#include <math/vec/vec4f.h>
#include <cmath>

namespace spruce {
	extern const float PI;

	[[nodiscard]] float clamp(const float& value, float min, float max);
	[[nodiscard]] float lerp(float a, float b, float alpha);
}
