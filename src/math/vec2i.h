#pragma once
#include <iostream>
#include <math.h>

namespace spruce {
    struct vec2i {
        int x;
        int y;

        vec2i();
		vec2i(const int& scalar);
		vec2i(const int& x, const int& y);

		float mag2() const;
		float mag() const;
		float dst2(const vec2i& vector) const;
		float dst(const vec2i& vector) const;
		float dot(const vec2i& vector) const;

		vec2i& add(const vec2i& vector);
		vec2i& sub(const vec2i& vector);

		vec2i& add(const int& value);
		vec2i& sub(const int& value);
		vec2i& scl(const int& value);
		vec2i& div(const int& value);

		friend vec2i operator+(const vec2i left, const vec2i& right);
		friend vec2i operator-(const vec2i left, const vec2i& right);

		friend vec2i operator+(const vec2i left, int value);
		friend vec2i operator-(const vec2i left, int value);
		friend vec2i operator*(const vec2i left, int value);
		friend vec2i operator/(const vec2i left, int value);

		bool operator==(const vec2i& vector) const;
		bool operator!=(const vec2i& vector) const;

		vec2i& operator+=(const vec2i& vector);
		vec2i& operator-=(const vec2i& vector);

		vec2i& operator+=(const int& value);
		vec2i& operator-=(const int& value);
		vec2i& operator*=(const int& value);
		vec2i& operator/=(const int& value);

		friend std::ostream& operator<<(std::ostream& stream, const vec2i& vector);
    };

    extern void log(const vec2i& vector);
}
