#pragma once
#include <common.h>

namespace spruce {
	struct color {
		float r = 0.0f;
		float g = 0.0f;
		float b = 0.0f;
		float a = 0.0f;

		color() = default;
		color(const color&) = default;
		color(color&&) noexcept = default;
		color(float r, float g, float b, float a);
		constexpr color(int32 hex);
		~color() = default;

		bool operator==(const color& color) const;
		bool operator!=(const color& color) const;

		color& operator=(const color&) = default;
		color& operator=(color&&) noexcept = default;

		friend std::ostream& operator<<(std::ostream& stream, const color& color);
	};
}

#include <graphics/colorImpl.h>
