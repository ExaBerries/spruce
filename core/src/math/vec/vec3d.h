#pragma once
#include <types.h>
#include <math/vec/vec2d.h>
#include <util/simd.h>
#include <iostream>
#include <cmath>

namespace spruce {
	struct alignas(alignof(simd::reg4d)) vec3d {
		double x = 0;
		double y = 0;
		double z = 0;

		private:
		[[maybe_unused]] double padding = 0;
		public:

		vec3d() = default;
		vec3d(double scalar);
		vec3d(const vec2d& vector, double z);
		vec3d(double x, double y, double z);
		vec3d(const vec3d&) = default;
		vec3d(vec3d&&) noexcept = default;
		~vec3d() = default;

		vec3d& set(const vec3d& vector) noexcept;
		vec3d& set(double x, double y, double z) noexcept;

		[[nodiscard]] double mag2() const noexcept;
		[[nodiscard]] double mag() const noexcept;
		vec3d& nor() noexcept;
		[[nodiscard]] double dst2(const vec3d& vector) const noexcept;
		[[nodiscard]] double dst(const vec3d& vector) const noexcept;
		[[nodiscard]] double dot(const vec3d& vector) const noexcept;
		vec3d& crs(const vec3d& vector) noexcept;

		vec3d& add(const vec3d& vector) noexcept;
		vec3d& sub(const vec3d& vector) noexcept;

		vec3d& add(double value) noexcept;
		vec3d& sub(double value) noexcept;
		vec3d& scl(double value) noexcept;
		vec3d& div(double value) noexcept;

		[[nodiscard]] bool operator==(const vec3d& vector) const noexcept;
		[[nodiscard]] bool operator!=(const vec3d& vector) const noexcept;

		vec3d& operator+=(const vec3d& vector) noexcept;
		vec3d& operator-=(const vec3d& vector) noexcept;

		vec3d& operator+=(double value) noexcept;
		vec3d& operator-=(double value) noexcept;
		vec3d& operator*=(double value) noexcept;
		vec3d& operator/=(double value) noexcept;

		vec3d& operator=(const vec3d&) = default;
		vec3d& operator=(vec3d&&) noexcept = default;

		[[nodiscard]] static vec3d lerp(const vec3d& a, const vec3d& b, double alpha) noexcept;
	};

	inline vec3d operator+(const vec3d& left, const vec3d& right) noexcept;
	inline vec3d operator-(const vec3d& left, const vec3d& right) noexcept;

	inline vec3d operator+(const vec3d& left, double value) noexcept;
	inline vec3d operator-(const vec3d& left, double value) noexcept;
	inline vec3d operator*(const vec3d& left, double value) noexcept;
	inline vec3d operator/(const vec3d& left, double value) noexcept;

	std::ostream& operator<<(std::ostream& stream, const vec3d& vector);
}

namespace std {
	template <>
	struct hash<spruce::vec3d>;
}

#include <math/vec/vec3dImpl.h>
