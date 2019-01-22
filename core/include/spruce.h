#pragma once

#include <types.h>
#include <common.h>
#include <app/app.h>
#include <math/math.h>
#include <input/input.h>
#include <graphics/graphics.h>
#include <task/async.h>
#include <system/time.h>
#include <io/io.h>
#include <memory/memory.h>
#include <SpruceEngine.h>

#define SPRUCE_MATH_ALIAS \
	using spruce::vec2f;\
	using spruce::vec2d;\
	using spruce::vec2i;\
	using spruce::vec3f;\
	using spruce::vec3d;\
	using spruce::vec3i;\
	using spruce::vec4f;\
	using spruce::quaternion;\
	using spruce::mat4f;

#ifdef TREE_ALIAS
#define 🌲 spruce;
#endif

namespace sp = spruce;
