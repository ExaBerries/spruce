#pragma once
#include <cstring>

namespace spruce {
	inline float mat4f::determinant() noexcept {
		float a = values[0] * (values[5] * (values[10] * values[15] - values[11] * values[14]) - values[6] * (values[9] * values[15] - values[11] * values[13]) + values[7] * (values[9] * values[14] - values[10] * values[13]));
		float b = values[1] * (values[4] * (values[10] * values[15] - values[11] * values[14]) - values[6] * (values[8] * values[15] - values[11] * values[12]) + values[7] * (values[8] * values[14] - values[10] * values[12]));
		float c = values[2] * (values[4] * (values[9] * values[15] - values[11] * values[13]) - values[5] * (values[8] * values[15] - values[11] * values[12]) + values[7] * (values[8] * values[13] - values[9] * values[12]));
		float d = values[3] * (values[4] * (values[9] * values[14] - values[10] * values[13]) - values[5] * (values[8] * values[14] - values[10] * values[12]) + values[6] * (values[8] * values[13] - values[9] * values[12]));
		return a - b + c - d;
	}

	inline mat4f& mat4f::invert() noexcept {
		float det = determinant();
		if (det == 0.0f) {
			return *this;
		}
		float tmpValues[16];
		tmpValues[0] = values[9] * values[14] * values[7] - values[13] * values[10] * values[7] + values[13] * values[6] * values[11] - values[5] * values[14] * values[11] - values[9] * values[6] * values[15] + values[5] * values[10] * values[15];
		tmpValues[1] = values[13] * values[10] * values[3] - values[9] * values[14] * values[3] - values[13] * values[2] * values[11] + values[1] * values[14] * values[11] + values[9] * values[2] * values[15] - values[1] * values[10] * values[15];
		tmpValues[2] = values[5] * values[14] * values[3] - values[13] * values[6] * values[3] + values[13] * values[2] * values[7] - values[1] * values[14] * values[7] - values[5] * values[2] * values[15] + values[1] * values[6] * values[15];
		tmpValues[3] = values[9] * values[6] * values[3] - values[5] * values[10] * values[3] - values[9] * values[2] * values[7] + values[1] * values[10] * values[7] + values[5] * values[2] * values[11] - values[1] * values[6] * values[11];
		tmpValues[4] = values[12] * values[10] * values[7] - values[8] * values[14] * values[7] - values[12] * values[6] * values[11] + values[4] * values[14] * values[11] + values[8] * values[6] * values[15] - values[4] * values[10] * values[15];
		tmpValues[5] = values[8] * values[14] * values[3] - values[12] * values[10] * values[3] + values[12] * values[2] * values[11] - values[0] * values[14] * values[11] - values[8] * values[2] * values[15] + values[0] * values[10] * values[15];
		tmpValues[6] = values[12] * values[6] * values[3] - values[4] * values[14] * values[3] - values[12] * values[2] * values[7] + values[0] * values[14] * values[7] + values[4] * values[2] * values[15] - values[0] * values[6] * values[15];
		tmpValues[7] = values[4] * values[10] * values[3] - values[8] * values[6] * values[3] + values[8] * values[2] * values[7] - values[0] * values[10] * values[7] - values[4] * values[2] * values[11] + values[0] * values[6] * values[11];
		tmpValues[8] = values[8] * values[13] * values[7] - values[12] * values[9] * values[7] + values[12] * values[5] * values[11] - values[4] * values[13] * values[11] - values[8] * values[5] * values[15] + values[4] * values[9] * values[15];
		tmpValues[9] = values[12] * values[9] * values[3] - values[8] * values[13] * values[3] - values[12] * values[1] * values[11] + values[0] * values[13] * values[11] + values[8] * values[1] * values[15] - values[0] * values[9] * values[15];
		tmpValues[10] = values[4] * values[13] * values[3] - values[12] * values[5] * values[3] + values[12] * values[1] * values[7] - values[0] * values[13] * values[7] - values[4] * values[1] * values[15] + values[0] * values[5] * values[15];
		tmpValues[11] = values[8] * values[5] * values[3] - values[4] * values[9] * values[3] - values[8] * values[1] * values[7] + values[0] * values[9] * values[7] + values[4] * values[1] * values[11] - values[0] * values[5] * values[11];
		tmpValues[12] = values[12] * values[9] * values[6] - values[8] * values[13] * values[6] - values[12] * values[5] * values[10] + values[4] * values[13] * values[10] + values[8] * values[5] * values[14] - values[4] * values[9] * values[14];
		tmpValues[13] = values[8] * values[13] * values[2] - values[12] * values[9] * values[2] + values[12] * values[1] * values[10] - values[0] * values[13] * values[10] - values[8] * values[1] * values[14] + values[0] * values[9] * values[14];
		tmpValues[14] = values[12] * values[5] * values[2] - values[4] * values[13] * values[2] - values[12] * values[1] * values[6] + values[0] * values[13] * values[6] + values[4] * values[1] * values[14] - values[0] * values[5] * values[14];
		tmpValues[15] = values[4] * values[9] * values[2] - values[8] * values[5] * values[2] + values[8] * values[1] * values[6] - values[0] * values[9] * values[6] - values[4] * values[1] * values[10] + values[0] * values[5] * values[10];
		simd::reg8f detr = simd::load1f8f(det);
		simd::reg8f r1r2 = simd::load8f8f(tmpValues[0]);
		simd::reg8f r3r4 = simd::load8f8f(tmpValues[8]);
		simd::store8f(values[0], simd::div8f(r1r2, detr));
		simd::store8f(values[8], simd::div8f(r3r4, detr));
		return *this;
	}

	inline mat4f& mat4f::transpose() noexcept {
		float tmp[16];
		tmp[0] = values[0];
		tmp[1] = values[4];
		tmp[2] = values[8];
		tmp[3] = values[12];
		tmp[4] = values[1];
		tmp[5] = values[5];
		tmp[6] = values[9];
		tmp[7] = values[13];
		tmp[8] = values[2];
		tmp[9] = values[6];
		tmp[10] = values[10];
		tmp[11] = values[14];
		tmp[12] = values[3];
		tmp[13] = values[7];
		tmp[14] = values[11];
		tmp[15] = values[15];
		memcpy(&values, &tmp, 16 * sizeof(float));
		return *this;
	}

	inline mat4f operator+(const mat4f& left, const mat4f& right) noexcept {
		float values[16];
		simd::reg8f la = simd::load8f8f(left.values[0]);
		simd::reg8f lb = simd::load8f8f(left.values[8]);
		simd::reg8f ra = simd::load8f8f(right.values[0]);
		simd::reg8f rb = simd::load8f8f(right.values[8]);
		simd::store8f(values[0], simd::add8f(la, ra));
		simd::store8f(values[8], simd::add8f(lb, rb));
		return *reinterpret_cast<mat4f*>(values);
	}

	inline mat4f operator-(const mat4f& left, const mat4f& right) noexcept {
		float values[16];
		simd::reg8f la = simd::load8f8f(left.values[0]);
		simd::reg8f lb = simd::load8f8f(left.values[8]);
		simd::reg8f ra = simd::load8f8f(right.values[0]);
		simd::reg8f rb = simd::load8f8f(right.values[8]);
		simd::store8f(values[0], simd::sub8f(la, ra));
		simd::store8f(values[8], simd::sub8f(lb, rb));
		return *reinterpret_cast<mat4f*>(values);
	}

	inline mat4f operator*(const mat4f& left, const mat4f& right) noexcept {
		float values[16];
		{ // row 1
			simd::reg4f a0 = simd::load1f4f(left.values[0]);
			simd::reg4f a1 = simd::load1f4f(left.values[1]);
			simd::reg4f a2 = simd::load1f4f(left.values[2]);
			simd::reg4f a3 = simd::load1f4f(left.values[3]);
			simd::reg4f br1 = simd::load4f4f(right.values[0]);
			simd::reg4f br2 = simd::load4f4f(right.values[4]);
			simd::reg4f br3 = simd::load4f4f(right.values[8]);
			simd::reg4f br4 = simd::load4f4f(right.values[12]);
			simd::store4f(values[0], simd::fmadd4f(a0, br1, simd::fmadd4f(a1, br2, simd::fmadd4f(a2, br3, simd::mul4f(a3, br4)))));
		}
		{ // row 2
			simd::reg4f a4 = simd::load1f4f(left.values[4]);
			simd::reg4f a5 = simd::load1f4f(left.values[5]);
			simd::reg4f a6 = simd::load1f4f(left.values[6]);
			simd::reg4f a7 = simd::load1f4f(left.values[7]);
			simd::reg4f br1 = simd::load4f4f(right.values[0]);
			simd::reg4f br2 = simd::load4f4f(right.values[4]);
			simd::reg4f br3 = simd::load4f4f(right.values[8]);
			simd::reg4f br4 = simd::load4f4f(right.values[12]);
			simd::store4f(values[4], simd::fmadd4f(a4, br1, simd::fmadd4f(a5, br2, simd::fmadd4f(a6, br3, simd::mul4f(a7, br4)))));
		}
		{ // row 3
			simd::reg4f a8 = simd::load1f4f(left.values[8]);
			simd::reg4f a9 = simd::load1f4f(left.values[9]);
			simd::reg4f a10 = simd::load1f4f(left.values[10]);
			simd::reg4f a11 = simd::load1f4f(left.values[11]);
			simd::reg4f br1 = simd::load4f4f(right.values[0]);
			simd::reg4f br2 = simd::load4f4f(right.values[4]);
			simd::reg4f br3 = simd::load4f4f(right.values[8]);
			simd::reg4f br4 = simd::load4f4f(right.values[12]);
			simd::store4f(values[8], simd::fmadd4f(a8, br1, simd::fmadd4f(a9, br2, simd::fmadd4f(a10, br3, simd::mul4f(a11, br4)))));
		}
		{ // row 4
			simd::reg4f a12 = simd::load1f4f(left.values[12]);
			simd::reg4f a13 = simd::load1f4f(left.values[13]);
			simd::reg4f a14 = simd::load1f4f(left.values[14]);
			simd::reg4f a15 = simd::load1f4f(left.values[15]);
			simd::reg4f br1 = simd::load4f4f(right.values[0]);
			simd::reg4f br2 = simd::load4f4f(right.values[4]);
			simd::reg4f br3 = simd::load4f4f(right.values[8]);
			simd::reg4f br4 = simd::load4f4f(right.values[12]);
			simd::store4f(values[12], simd::fmadd4f(a12, br1, simd::fmadd4f(a13, br2, simd::fmadd4f(a14, br3, simd::mul4f(a15, br4)))));
		}
		return *reinterpret_cast<mat4f*>(values);
	}

	inline vec3f operator*(const vec3f& vector, const mat4f& matrix) noexcept {
		float tmp[16];
		tmp[0] = matrix.values[0];
		tmp[1] = matrix.values[4];
		tmp[2] = matrix.values[8];
		tmp[3] = matrix.values[12];
		tmp[4] = matrix.values[1];
		tmp[5] = matrix.values[5];
		tmp[6] = matrix.values[9];
		tmp[7] = matrix.values[13];
		tmp[8] = matrix.values[2];
		tmp[9] = matrix.values[6];
		tmp[10] = matrix.values[10];
		tmp[11] = matrix.values[14];
		tmp[12] = matrix.values[3];
		tmp[13] = matrix.values[7];
		tmp[14] = matrix.values[11];
		tmp[15] = matrix.values[15];
		simd::reg4f c0 = simd::load4f4f(tmp[0]);
		simd::reg4f c1 = simd::load4f4f(tmp[4]);
		simd::reg4f c2 = simd::load4f4f(tmp[8]);
		simd::reg4f c3 = simd::load4f4f(tmp[12]);
		simd::reg4f x = simd::load1f4f(vector.x);
		simd::reg4f y = simd::load1f4f(vector.y);
		simd::reg4f z = simd::load1f4f(vector.z);
		simd::reg4f w = simd::load1f4f(1);
		simd::reg4f p1 = simd::mul4f(x, c0);
		simd::reg4f p2 = simd::fmadd4f(y, c1, p1);
		simd::reg4f p3 = simd::mul4f(z, c2);
		simd::reg4f p4 = simd::fmadd4f(w, c3, p3);
		float vec[4];
		simd::store4f(vec[0], simd::add4f(p2, p4));
		return *reinterpret_cast<vec3f*>(vec);
	}

	inline vec3f operator*(const mat4f& matrix, const vec3f& vector) noexcept {
		float tmp[16];
		tmp[0] = matrix.values[0];
		tmp[1] = matrix.values[4];
		tmp[2] = matrix.values[8];
		tmp[3] = matrix.values[12];
		tmp[4] = matrix.values[1];
		tmp[5] = matrix.values[5];
		tmp[6] = matrix.values[9];
		tmp[7] = matrix.values[13];
		tmp[8] = matrix.values[2];
		tmp[9] = matrix.values[6];
		tmp[10] = matrix.values[10];
		tmp[11] = matrix.values[14];
		tmp[12] = matrix.values[3];
		tmp[13] = matrix.values[7];
		tmp[14] = matrix.values[11];
		tmp[15] = matrix.values[15];
		simd::reg4f c0 = simd::load4f4f(tmp[0]);
		simd::reg4f c1 = simd::load4f4f(tmp[4]);
		simd::reg4f c2 = simd::load4f4f(tmp[8]);
		simd::reg4f c3 = simd::load4f4f(tmp[12]);
		simd::reg4f x = simd::load1f4f(vector.x);
		simd::reg4f y = simd::load1f4f(vector.y);
		simd::reg4f z = simd::load1f4f(vector.z);
		simd::reg4f w = simd::load1f4f(1);
		simd::reg4f p1 = simd::mul4f(x, c0);
		simd::reg4f p2 = simd::fmadd4f(y, c1, p1);
		simd::reg4f p3 = simd::mul4f(z, c2);
		simd::reg4f p4 = simd::fmadd4f(w, c3, p3);
		float vec[4];
		simd::store4f(vec[0], simd::add4f(p2, p4));
		return *reinterpret_cast<vec3f*>(vec);
	}

	inline vec4f operator*(const vec4f& vector, const mat4f& matrix) noexcept {
		float tmp[16];
		tmp[0] = matrix.values[0];
		tmp[1] = matrix.values[4];
		tmp[2] = matrix.values[8];
		tmp[3] = matrix.values[12];
		tmp[4] = matrix.values[1];
		tmp[5] = matrix.values[5];
		tmp[6] = matrix.values[9];
		tmp[7] = matrix.values[13];
		tmp[8] = matrix.values[2];
		tmp[9] = matrix.values[6];
		tmp[10] = matrix.values[10];
		tmp[11] = matrix.values[14];
		tmp[12] = matrix.values[3];
		tmp[13] = matrix.values[7];
		tmp[14] = matrix.values[11];
		tmp[15] = matrix.values[15];
		simd::reg4f c0 = simd::load4f4f(tmp[0]);
		simd::reg4f c1 = simd::load4f4f(tmp[4]);
		simd::reg4f c2 = simd::load4f4f(tmp[8]);
		simd::reg4f c3 = simd::load4f4f(tmp[12]);
		simd::reg4f x = simd::load1f4f(vector.x);
		simd::reg4f y = simd::load1f4f(vector.y);
		simd::reg4f z = simd::load1f4f(vector.z);
		simd::reg4f w = simd::load1f4f(vector.w);
		simd::reg4f p1 = simd::mul4f(x, c0);
		simd::reg4f p2 = simd::fmadd4f(y, c1, p1);
		simd::reg4f p3 = simd::mul4f(z, c2);
		simd::reg4f p4 = simd::fmadd4f(w, c3, p3);
		float vec[4];
		simd::store4f(vec[0], simd::add4f(p2, p4));
		return *reinterpret_cast<vec4f*>(vec);
	}

	inline vec4f operator*(const mat4f& matrix, const vec4f& vector) noexcept {
		float tmp[16];
		tmp[0] = matrix.values[0];
		tmp[1] = matrix.values[4];
		tmp[2] = matrix.values[8];
		tmp[3] = matrix.values[12];
		tmp[4] = matrix.values[1];
		tmp[5] = matrix.values[5];
		tmp[6] = matrix.values[9];
		tmp[7] = matrix.values[13];
		tmp[8] = matrix.values[2];
		tmp[9] = matrix.values[6];
		tmp[10] = matrix.values[10];
		tmp[11] = matrix.values[14];
		tmp[12] = matrix.values[3];
		tmp[13] = matrix.values[7];
		tmp[14] = matrix.values[11];
		tmp[15] = matrix.values[15];
		simd::reg4f r0 = simd::load4f4f(tmp[0]);
		simd::reg4f r1 = simd::load4f4f(tmp[4]);
		simd::reg4f r2 = simd::load4f4f(tmp[8]);
		simd::reg4f r3 = simd::load4f4f(tmp[12]);
		simd::reg4f x = simd::load1f4f(vector.x);
		simd::reg4f y = simd::load1f4f(vector.y);
		simd::reg4f z = simd::load1f4f(vector.z);
		simd::reg4f w = simd::load1f4f(vector.w);
		simd::reg4f p1 = simd::mul4f(x, r0);
		simd::reg4f p2 = simd::fmadd4f(y, r1, p1);
		simd::reg4f p3 = simd::mul4f(z, r2);
		simd::reg4f p4 = simd::fmadd4f(w, r3, p3);
		float vec[4];
		simd::store4f(vec[0], simd::add4f(p2, p4));
		return *reinterpret_cast<vec4f*>(vec);
	}

	inline mat4f& mat4f::operator+=(const mat4f& matrix) noexcept {
		simd::reg8f ta = simd::load8f8f(values[0]);
		simd::reg8f tb = simd::load8f8f(values[8]);
		simd::reg8f ma = simd::load8f8f(matrix.values[0]);
		simd::reg8f mb = simd::load8f8f(matrix.values[8]);
		simd::store8f(values[0], simd::add8f(ta, ma));
		simd::store8f(values[8], simd::add8f(tb, mb));
		return *this;
	}

	inline mat4f& mat4f::operator-=(const mat4f& matrix) noexcept {
		simd::reg8f ta = simd::load8f8f(values[0]);
		simd::reg8f tb = simd::load8f8f(values[8]);
		simd::reg8f ma = simd::load8f8f(matrix.values[0]);
		simd::reg8f mb = simd::load8f8f(matrix.values[8]);
		simd::store8f(values[0], simd::sub8f(ta, ma));
		simd::store8f(values[8], simd::sub8f(tb, mb));
		return *this;
	}

	inline mat4f& mat4f::operator*=(const mat4f& matrix) noexcept {
		{ // row 1
			simd::reg4f a0 = simd::load1f4f(values[0]);
			simd::reg4f a1 = simd::load1f4f(values[1]);
			simd::reg4f a2 = simd::load1f4f(values[2]);
			simd::reg4f a3 = simd::load1f4f(values[3]);
			simd::reg4f br1 = simd::load4f4f(matrix.values[0]);
			simd::reg4f br2 = simd::load4f4f(matrix.values[4]);
			simd::reg4f br3 = simd::load4f4f(matrix.values[8]);
			simd::reg4f br4 = simd::load4f4f(matrix.values[12]);
			simd::store4f(values[0], simd::fmadd4f(a0, br1, simd::fmadd4f(a1, br2, simd::fmadd4f(a2, br3, simd::mul4f(a3, br4)))));
		}
		{ // row 2
			simd::reg4f a4 = simd::load1f4f(values[4]);
			simd::reg4f a5 = simd::load1f4f(values[5]);
			simd::reg4f a6 = simd::load1f4f(values[6]);
			simd::reg4f a7 = simd::load1f4f(values[7]);
			simd::reg4f br1 = simd::load4f4f(matrix.values[0]);
			simd::reg4f br2 = simd::load4f4f(matrix.values[4]);
			simd::reg4f br3 = simd::load4f4f(matrix.values[8]);
			simd::reg4f br4 = simd::load4f4f(matrix.values[12]);
			simd::store4f(values[4], simd::fmadd4f(a4, br1, simd::fmadd4f(a5, br2, simd::fmadd4f(a6, br3, simd::mul4f(a7, br4)))));
		}
		{ // row 3
			simd::reg4f a8 = simd::load1f4f(values[8]);
			simd::reg4f a9 = simd::load1f4f(values[9]);
			simd::reg4f a10 = simd::load1f4f(values[10]);
			simd::reg4f a11 = simd::load1f4f(values[11]);
			simd::reg4f br1 = simd::load4f4f(matrix.values[0]);
			simd::reg4f br2 = simd::load4f4f(matrix.values[4]);
			simd::reg4f br3 = simd::load4f4f(matrix.values[8]);
			simd::reg4f br4 = simd::load4f4f(matrix.values[12]);
			simd::store4f(values[8], simd::fmadd4f(a8, br1, simd::fmadd4f(a9, br2, simd::fmadd4f(a10, br3, simd::mul4f(a11, br4)))));
		}
		{ // row 4
			simd::reg4f a12 = simd::load1f4f(values[12]);
			simd::reg4f a13 = simd::load1f4f(values[13]);
			simd::reg4f a14 = simd::load1f4f(values[14]);
			simd::reg4f a15 = simd::load1f4f(values[15]);
			simd::reg4f br1 = simd::load4f4f(matrix.values[0]);
			simd::reg4f br2 = simd::load4f4f(matrix.values[4]);
			simd::reg4f br3 = simd::load4f4f(matrix.values[8]);
			simd::reg4f br4 = simd::load4f4f(matrix.values[12]);
			simd::store4f(values[12], simd::fmadd4f(a12, br1, simd::fmadd4f(a13, br2, simd::fmadd4f(a14, br3, simd::mul4f(a15, br4)))));
		}
		return *reinterpret_cast<mat4f*>(values);
	}
}

namespace std {
	template <>
	struct hash<spruce::mat4f> {
		size_t operator()(const spruce::mat4f& m) const {
			size_t hashValue = 0;
			for (uint16 i = 0; i < 16; i++) {
				hashValue ^= std::hash<float>()(m.values[i]) + 0x9e3779b9 + (hashValue << 6) + (hashValue >> 2);
			}
			return hashValue;
		}
	};
}
