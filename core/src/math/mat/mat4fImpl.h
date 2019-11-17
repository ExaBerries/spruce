#pragma once
#include <cstring>

namespace spruce {
	constexpr mat4f::mat4f(const float values[16]) noexcept {
		if (std::is_constant_evaluated()) {
			for (uint8 i = 0; i < 16; i++) {
				this->values[i] = values[i];
			}
		} else {
			simd::store8f(this->values[0], simd::load8f8f(values[0]));
			simd::store8f(this->values[8], simd::load8f8f(values[8]));
		}
	}

	constexpr mat4f::mat4f(const vec3f& translation, const quaternion& rotation, const vec3f& scale) noexcept {
		float x2 = rotation.x * rotation.x;
		float y2 = rotation.y * rotation.y;
		float z2 = rotation.z * rotation.z;
		float wx = rotation.w * rotation.x;
		float wy = rotation.w * rotation.y;
		float wz = rotation.w * rotation.z;
		values[0] = scale.x * (1.0f - y2 * 2.0f + z2 * 2.0f);
		values[1] = scale.y * (rotation.x * rotation.y * 2.0f - wz);
		values[2] = scale.z * (rotation.x * rotation.z * 2.0f + wy);
		values[3] = translation.x;
		values[4] = scale.x * (rotation.x * rotation.y * 2.0f + wz);
		values[5] = scale.y * (1.0f - (x2 * 2.0f + z2 * 2.0f));
		values[6] = scale.z * (rotation.y * rotation.z * 2.0f - wx);
		values[7] = translation.y;
		values[8] = scale.x * (rotation.x * rotation.z * 2.0f - wy);
		values[9] = scale.y * (rotation.y * rotation.z * 2.0f + wx);
		values[10] = scale.z * (1.0f - (x2 * 2.0f + y2 * 2.0f));
		values[11] = translation.z;
		values[12] = 0.0f;
		values[13] = 0.0f;
		values[14] = 0.0f;
		values[15] = 1.0f;
	}

	constexpr mat4f::mat4f(const vec3f& direction, const vec3f& up) noexcept {
		vec3f dirNor = vec3f(direction).nor();
		vec3f dirCrsUp = vec3f(dirNor).crs(up).nor();
		vec3f dirCrsUpCrsDir = vec3f(dirCrsUp).crs(dirNor).nor();
		values[0] = dirCrsUp.x;
		values[1] = dirCrsUpCrsDir.x;
		values[2] = -dirNor.x;
		values[3] = 0.0f;
		values[4] = dirCrsUp.y;
		values[5] = dirCrsUpCrsDir.y;
		values[6] = -dirNor.y;
		values[7] = 0.0f;
		values[8] = dirCrsUp.z;
		values[9] = dirCrsUpCrsDir.z;
		values[10] = -dirNor.z;
		values[11] = 0.0f;
		values[12] = 0.0f;
		values[13] = 0.0f;
		values[14] = 0.0f;
		values[15] = 1.0f;
	}

	constexpr mat4f::mat4f(float v0, float v1, float v2, float v3, float v4, float v5, float v6, float v7, float v8, float v9, float v10, float v11, float v12, float v13, float v14, float v15) noexcept {
		values[0] = v0;
		values[1] = v1;
		values[2] = v2;
		values[3] = v3;
		values[4] = v4;
		values[5] = v5;
		values[6] = v6;
		values[7] = v7;
		values[8] = v8;
		values[9] = v9;
		values[10] = v10;
		values[11] = v11;
		values[12] = v12;
		values[13] = v13;
		values[14] = v14;
		values[15] = v15;
	}

	constexpr mat4f& mat4f::setIdentity() noexcept {
		values[0] = 1.0f;
		values[1] = 0.0f;
		values[2] = 0.0f;
		values[3] = 0.0f;
		values[4] = 0.0f;
		values[5] = 1.0f;
		values[6] = 0.0f;
		values[7] = 0.0f;
		values[8] = 0.0f;
		values[9] = 0.0f;
		values[10] = 1.0f;
		values[11] = 0.0f;
		values[12] = 0.0f;
		values[13] = 0.0f;
		values[14] = 0.0f;
		values[15] = 1.0f;
		return *this;
	}

	constexpr mat4f& mat4f::set(const float nvalues[16]) noexcept {
		if (std::is_constant_evaluated()) {
			memcpy(&values[0], &nvalues[0], sizeof(float) * 16);
		} else {
			simd::store8f(values[0], simd::load8f8f(nvalues[0]));
			simd::store8f(values[8], simd::load8f8f(nvalues[8]));
		}
		return *this;
	}

	constexpr mat4f& mat4f::set(const vec3f& translation, const quaternion& rotation, const vec3f& scale) noexcept {
		float x2 = rotation.x * rotation.x;
		float y2 = rotation.y * rotation.y;
		float z2 = rotation.z * rotation.z;
		float wx = rotation.w * rotation.x;
		float wy = rotation.w * rotation.y;
		float wz = rotation.w * rotation.z;
		values[0] = scale.x * (1.0f - (y2 * 2.0f + z2 * 2.0f));
		values[1] = scale.y * (rotation.x * rotation.y * 2.0f - wz);
		values[2] = scale.z * (rotation.x * rotation.z * 2.0f + wy);
		values[3] = translation.x;
		values[4] = scale.x * (rotation.x * rotation.y * 2.0f + wz);
		values[5] = scale.y * (1.0f - (x2 * 2.0f + z2 * 2.0f));
		values[6] = scale.z * (rotation.y * rotation.z * 2.0f - wx);
		values[7] = translation.y;
		values[8] = scale.x * (rotation.x * rotation.z * 2.0f - wy);
		values[9] = scale.y * (rotation.y * rotation.z * 2.0f + wx);
		values[10] = scale.z * (1.0f - (x2 * 2.0f + y2 * 2.0f));
		values[11] = translation.z;
		values[12] = 0.0f;
		values[13] = 0.0f;
		values[14] = 0.0f;
		values[15] = 1.0f;
		return *this;
	}

	constexpr mat4f& mat4f::set(const vec3f& direction, const vec3f& up) noexcept {
		vec3f dirNor = vec3f(direction).nor();
		vec3f dirCrsUp = vec3f(dirNor).crs(up).nor();
		vec3f dirCrsUpCrsDir = vec3f(dirCrsUp).crs(dirNor).nor();
		values[0] = dirCrsUp.x;
		values[1] = dirCrsUp.y;
		values[2] = dirCrsUp.z;
		values[3] = 0.0f;
		values[4] = dirCrsUpCrsDir.x;
		values[5] = dirCrsUpCrsDir.y;
		values[6] = dirCrsUpCrsDir.z;
		values[7] = 0.0f;
		values[8] = -dirNor.x;
		values[9] = -dirNor.y;
		values[10] = -dirNor.z;
		values[11] = 0.0f;
		values[12] = 0.0f;
		values[13] = 0.0f;
		values[14] = 0.0f;
		values[15] = 1.0f;
		return *this;
	}

	constexpr bool mat4f::operator==(const mat4f& matrix) const noexcept {
		for (uint8 i = 0; i < 16; i++) {
			if (values[i] != matrix.values[i]) {
				return false;
			}
		}
		return true;
	}

	constexpr bool mat4f::operator!=(const mat4f& matrix) const noexcept {
		for (uint8 i = 0; i < 16; i++) {
			if (values[i] != matrix.values[i]) {
				return true;
			}
		}
		return false;
	}

	constexpr float mat4f::determinant() const noexcept {
		float a = values[0] * (values[5] * (values[10] * values[15] - values[11] * values[14]) - values[6] * (values[9] * values[15] - values[11] * values[13]) + values[7] * (values[9] * values[14] - values[10] * values[13]));
		float b = values[1] * (values[4] * (values[10] * values[15] - values[11] * values[14]) - values[6] * (values[8] * values[15] - values[11] * values[12]) + values[7] * (values[8] * values[14] - values[10] * values[12]));
		float c = values[2] * (values[4] * (values[9] * values[15] - values[11] * values[13]) - values[5] * (values[8] * values[15] - values[11] * values[12]) + values[7] * (values[8] * values[13] - values[9] * values[12]));
		float d = values[3] * (values[4] * (values[9] * values[14] - values[10] * values[13]) - values[5] * (values[8] * values[14] - values[10] * values[12]) + values[6] * (values[8] * values[13] - values[9] * values[12]));
		return a - b + c - d;
	}

	constexpr mat4f& mat4f::invert() noexcept {
		float det = determinant();
		if (det == 0.0f) {
			return *this;
		}
		float tmpValues[16] = {
			values[9] * values[14] * values[7] - values[13] * values[10] * values[7] + values[13] * values[6] * values[11] - values[5] * values[14] * values[11] - values[9] * values[6] * values[15] + values[5] * values[10] * values[15],
			values[13] * values[10] * values[3] - values[9] * values[14] * values[3] - values[13] * values[2] * values[11] + values[1] * values[14] * values[11] + values[9] * values[2] * values[15] - values[1] * values[10] * values[15],
			values[5] * values[14] * values[3] - values[13] * values[6] * values[3] + values[13] * values[2] * values[7] - values[1] * values[14] * values[7] - values[5] * values[2] * values[15] + values[1] * values[6] * values[15],
			values[9] * values[6] * values[3] - values[5] * values[10] * values[3] - values[9] * values[2] * values[7] + values[1] * values[10] * values[7] + values[5] * values[2] * values[11] - values[1] * values[6] * values[11],
			values[12] * values[10] * values[7] - values[8] * values[14] * values[7] - values[12] * values[6] * values[11] + values[4] * values[14] * values[11] + values[8] * values[6] * values[15] - values[4] * values[10] * values[15],
			values[8] * values[14] * values[3] - values[12] * values[10] * values[3] + values[12] * values[2] * values[11] - values[0] * values[14] * values[11] - values[8] * values[2] * values[15] + values[0] * values[10] * values[15],
			values[12] * values[6] * values[3] - values[4] * values[14] * values[3] - values[12] * values[2] * values[7] + values[0] * values[14] * values[7] + values[4] * values[2] * values[15] - values[0] * values[6] * values[15],
			values[4] * values[10] * values[3] - values[8] * values[6] * values[3] + values[8] * values[2] * values[7] - values[0] * values[10] * values[7] - values[4] * values[2] * values[11] + values[0] * values[6] * values[11],
			values[8] * values[13] * values[7] - values[12] * values[9] * values[7] + values[12] * values[5] * values[11] - values[4] * values[13] * values[11] - values[8] * values[5] * values[15] + values[4] * values[9] * values[15],
			values[12] * values[9] * values[3] - values[8] * values[13] * values[3] - values[12] * values[1] * values[11] + values[0] * values[13] * values[11] + values[8] * values[1] * values[15] - values[0] * values[9] * values[15],
			values[4] * values[13] * values[3] - values[12] * values[5] * values[3] + values[12] * values[1] * values[7] - values[0] * values[13] * values[7] - values[4] * values[1] * values[15] + values[0] * values[5] * values[15],
			values[8] * values[5] * values[3] - values[4] * values[9] * values[3] - values[8] * values[1] * values[7] + values[0] * values[9] * values[7] + values[4] * values[1] * values[11] - values[0] * values[5] * values[11],
			values[12] * values[9] * values[6] - values[8] * values[13] * values[6] - values[12] * values[5] * values[10] + values[4] * values[13] * values[10] + values[8] * values[5] * values[14] - values[4] * values[9] * values[14],
			values[8] * values[13] * values[2] - values[12] * values[9] * values[2] + values[12] * values[1] * values[10] - values[0] * values[13] * values[10] - values[8] * values[1] * values[14] + values[0] * values[9] * values[14],
			values[12] * values[5] * values[2] - values[4] * values[13] * values[2] - values[12] * values[1] * values[6] + values[0] * values[13] * values[6] + values[4] * values[1] * values[14] - values[0] * values[5] * values[14],
			values[4] * values[9] * values[2] - values[8] * values[5] * values[2] + values[8] * values[1] * values[6] - values[0] * values[9] * values[6] - values[4] * values[1] * values[10] + values[0] * values[5] * values[10]
		};
		if (std::is_constant_evaluated()) {
			values[0] = tmpValues[0] / det;
			values[1] = tmpValues[1] / det;
			values[2] = tmpValues[2] / det;
			values[3] = tmpValues[3] / det;
			values[4] = tmpValues[4] / det;
			values[5] = tmpValues[5] / det;
			values[6] = tmpValues[6] / det;
			values[7] = tmpValues[7] / det;
			values[8] = tmpValues[8] / det;
			values[9] = tmpValues[9] / det;
			values[12] = tmpValues[12] / det;
			values[10] = tmpValues[10] / det;
			values[13] = tmpValues[13] / det;
			values[14] = tmpValues[14] / det;
			values[11] = tmpValues[11] / det;
			values[15] = tmpValues[15] / det;
		} else {
			simd::reg8f detr = simd::load1f8f(det);
			simd::reg8f r1r2 = simd::load8f8f(tmpValues[0]);
			simd::reg8f r3r4 = simd::load8f8f(tmpValues[8]);
			simd::store8f(values[0], simd::div8f(r1r2, detr));
			simd::store8f(values[8], simd::div8f(r3r4, detr));
		}
		return *this;
	}

	constexpr mat4f& mat4f::transpose() noexcept {
		float tmp[16] = {
			values[0],
			values[4],
			values[8],
			values[12],
			values[1],
			values[5],
			values[9],
			values[13],
			values[2],
			values[6],
			values[10],
			values[14],
			values[3],
			values[7],
			values[11],
			values[15],
		};
		for (uint8 i = 0; i < 16; i++) {
			values[i] = tmp[i];
		}
		return *this;
	}

	constexpr mat4f operator+(const mat4f& left, const mat4f& right) noexcept {
		if (std::is_constant_evaluated()) {
			return {
				left.values[0] + right.values[0],
				left.values[1] + right.values[1],
				left.values[2] + right.values[2],
				left.values[3] + right.values[3],
				left.values[4] + right.values[4],
				left.values[5] + right.values[5],
				left.values[6] + right.values[6],
				left.values[7] + right.values[7],
				left.values[8] + right.values[8],
				left.values[9] + right.values[9],
				left.values[10] + right.values[10],
				left.values[11] + right.values[11],
				left.values[12] + right.values[12],
				left.values[13] + right.values[13],
				left.values[14] + right.values[14],
				left.values[15] + right.values[15]
			};
		} else {
			mat4f result;
			simd::reg8f la = simd::load8f8f(left.values[0]);
			simd::reg8f lb = simd::load8f8f(left.values[8]);
			simd::reg8f ra = simd::load8f8f(right.values[0]);
			simd::reg8f rb = simd::load8f8f(right.values[8]);
			simd::store8f(result.values[0], simd::add8f(la, ra));
			simd::store8f(result.values[8], simd::add8f(lb, rb));
			return result;
		}
	}

	constexpr mat4f operator-(const mat4f& left, const mat4f& right) noexcept {
		if (std::is_constant_evaluated()) {
			return {
				left.values[0] - right.values[0],
				left.values[1] - right.values[1],
				left.values[2] - right.values[2],
				left.values[3] - right.values[3],
				left.values[4] - right.values[4],
				left.values[5] - right.values[5],
				left.values[6] - right.values[6],
				left.values[7] - right.values[7],
				left.values[8] - right.values[8],
				left.values[9] - right.values[9],
				left.values[10] - right.values[10],
				left.values[11] - right.values[11],
				left.values[12] - right.values[12],
				left.values[13] - right.values[13],
				left.values[14] - right.values[14],
				left.values[15] - right.values[15]
			};
		} else {
			mat4f result;
			simd::reg8f la = simd::load8f8f(left.values[0]);
			simd::reg8f lb = simd::load8f8f(left.values[8]);
			simd::reg8f ra = simd::load8f8f(right.values[0]);
			simd::reg8f rb = simd::load8f8f(right.values[8]);
			simd::store8f(result.values[0], simd::sub8f(la, ra));
			simd::store8f(result.values[8], simd::sub8f(lb, rb));
			return result;
		}
	}

	constexpr mat4f operator*(const mat4f& left, const mat4f& right) noexcept {
		if (std::is_constant_evaluated()) {
			return {
				left.values[0] * right.values[0] + left.values[1] * right.values[4] + left.values[2] * right.values[8] + left.values[3] * right.values[12],
				left.values[0] * right.values[1] + left.values[1] * right.values[5] + left.values[2] * right.values[9] + left.values[3] * right.values[13],
				left.values[0] * right.values[2] + left.values[1] * right.values[6] + left.values[2] * right.values[10] + left.values[3] * right.values[14],
				left.values[0] * right.values[3] + left.values[1] * right.values[7] + left.values[2] * right.values[11] + left.values[3] * right.values[15],
				left.values[4] * right.values[0] + left.values[5] * right.values[4] + left.values[6] * right.values[8] + left.values[7] * right.values[12],
				left.values[4] * right.values[1] + left.values[5] * right.values[5] + left.values[6] * right.values[9] + left.values[7] * right.values[13],
				left.values[4] * right.values[2] + left.values[5] * right.values[6] + left.values[6] * right.values[10] + left.values[7] * right.values[14],
				left.values[4] * right.values[3] + left.values[5] * right.values[7] + left.values[6] * right.values[11] + left.values[7] * right.values[15],
				left.values[8] * right.values[0] + left.values[9] * right.values[4] + left.values[10] * right.values[8] + left.values[11] * right.values[12],
				left.values[8] * right.values[1] + left.values[9] * right.values[5] + left.values[10] * right.values[9] + left.values[11] * right.values[13],
				left.values[8] * right.values[2] + left.values[9] * right.values[6] + left.values[10] * right.values[10] + left.values[11] * right.values[14],
				left.values[8] * right.values[3] + left.values[9] * right.values[7] + left.values[10] * right.values[11] + left.values[11] * right.values[15],
				left.values[12] * right.values[0] + left.values[13] * right.values[4] + left.values[14] * right.values[8] + left.values[15] * right.values[12],
				left.values[12] * right.values[1] + left.values[13] * right.values[5] + left.values[14] * right.values[9] + left.values[15] * right.values[13],
				left.values[12] * right.values[2] + left.values[13] * right.values[6] + left.values[14] * right.values[10] + left.values[15] * right.values[14],
				left.values[12] * right.values[3] + left.values[13] * right.values[7] + left.values[14] * right.values[11] + left.values[15] * right.values[15]
			};
		} else {
			mat4f result;
			{ // row 1
				simd::reg4f a0 = simd::load1f4f(left.values[0]);
				simd::reg4f a1 = simd::load1f4f(left.values[1]);
				simd::reg4f a2 = simd::load1f4f(left.values[2]);
				simd::reg4f a3 = simd::load1f4f(left.values[3]);
				simd::reg4f br1 = simd::load4f4f(right.values[0]);
				simd::reg4f br2 = simd::load4f4f(right.values[4]);
				simd::reg4f br3 = simd::load4f4f(right.values[8]);
				simd::reg4f br4 = simd::load4f4f(right.values[12]);
				simd::store4f(result.values[0], simd::fmadd4f(a0, br1, simd::fmadd4f(a1, br2, simd::fmadd4f(a2, br3, simd::mul4f(a3, br4)))));
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
				simd::store4f(result.values[4], simd::fmadd4f(a4, br1, simd::fmadd4f(a5, br2, simd::fmadd4f(a6, br3, simd::mul4f(a7, br4)))));
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
				simd::store4f(result.values[8], simd::fmadd4f(a8, br1, simd::fmadd4f(a9, br2, simd::fmadd4f(a10, br3, simd::mul4f(a11, br4)))));
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
				simd::store4f(result.values[12], simd::fmadd4f(a12, br1, simd::fmadd4f(a13, br2, simd::fmadd4f(a14, br3, simd::mul4f(a15, br4)))));
			}
			return result;
		}
	}

	constexpr vec3f operator*(const vec3f& vector, const mat4f& matrix) noexcept {
		if (std::is_constant_evaluated()) {
			float x = vector.x * matrix.values[0] + vector.y * matrix.values[1] + vector.z * matrix.values[2] + matrix.values[3];
			float y = vector.x * matrix.values[4] + vector.y * matrix.values[5] + vector.z * matrix.values[6] + matrix.values[7];
			float z = vector.x * matrix.values[8] + vector.y * matrix.values[9] + vector.z * matrix.values[10] + matrix.values[11];
			return {x, y, z};
		} else {
			float tmp[16] = {
				matrix.values[0],
				matrix.values[4],
				matrix.values[8],
				matrix.values[12],
				matrix.values[1],
				matrix.values[5],
				matrix.values[9],
				matrix.values[13],
				matrix.values[2],
				matrix.values[6],
				matrix.values[10],
				matrix.values[14],
				matrix.values[3],
				matrix.values[7],
				matrix.values[11],
				matrix.values[15]
			};
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
			vec3f result;
			simd::store4f(result.x, simd::add4f(p2, p4));
			return result;
		}
	}

	constexpr vec3f operator*(const mat4f& matrix, const vec3f& vector) noexcept {
		if (std::is_constant_evaluated()) {
			float x = vector.x * matrix.values[0] + vector.y * matrix.values[1] + vector.z * matrix.values[2] + matrix.values[3];
			float y = vector.x * matrix.values[4] + vector.y * matrix.values[5] + vector.z * matrix.values[6] + matrix.values[7];
			float z = vector.x * matrix.values[8] + vector.y * matrix.values[9] + vector.z * matrix.values[10] + matrix.values[11];
			return {x, y, z};
		} else {
			float tmp[16] = {
				matrix.values[0],
				matrix.values[4],
				matrix.values[8],
				matrix.values[12],
				matrix.values[1],
				matrix.values[5],
				matrix.values[9],
				matrix.values[13],
				matrix.values[2],
				matrix.values[6],
				matrix.values[10],
				matrix.values[14],
				matrix.values[3],
				matrix.values[7],
				matrix.values[11],
				matrix.values[15]
			};
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
			vec3f result;
			simd::store4f(result.x, simd::add4f(p2, p4));
			return result;
		}
	}

	constexpr vec4f operator*(const vec4f& vector, const mat4f& matrix) noexcept {
		if (std::is_constant_evaluated()) {
			float x = vector.x * matrix.values[0] + vector.y * matrix.values[1] + vector.z * matrix.values[2] + vector.w * matrix.values[3];
			float y = vector.x * matrix.values[4] + vector.y * matrix.values[5] + vector.z * matrix.values[6] + vector.w * matrix.values[7];
			float z = vector.x * matrix.values[8] + vector.y * matrix.values[9] + vector.z * matrix.values[10] + vector.w * matrix.values[11];
			float w = vector.x * matrix.values[12] + vector.y * matrix.values[13] + vector.z * matrix.values[14] + vector.w * matrix.values[15];
			return {x, y, z, w};
		} else {
			float tmp[16] = {
				matrix.values[0],
				matrix.values[4],
				matrix.values[8],
				matrix.values[12],
				matrix.values[1],
				matrix.values[5],
				matrix.values[9],
				matrix.values[13],
				matrix.values[2],
				matrix.values[6],
				matrix.values[10],
				matrix.values[14],
				matrix.values[3],
				matrix.values[7],
				matrix.values[11],
				matrix.values[15]
			};
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
			vec4f result;
			simd::store4f(result.x, simd::add4f(p2, p4));
			return result;
		}
	}

	constexpr vec4f operator*(const mat4f& matrix, const vec4f& vector) noexcept {
		if (std::is_constant_evaluated()) {
			float x = vector.x * matrix.values[0] + vector.y * matrix.values[1] + vector.z * matrix.values[2] + vector.w * matrix.values[3];
			float y = vector.x * matrix.values[4] + vector.y * matrix.values[5] + vector.z * matrix.values[6] + vector.w * matrix.values[7];
			float z = vector.x * matrix.values[8] + vector.y * matrix.values[9] + vector.z * matrix.values[10] + vector.w * matrix.values[11];
			float w = vector.x * matrix.values[12] + vector.y * matrix.values[13] + vector.z * matrix.values[14] + vector.w * matrix.values[15];
			return {x, y, z, w};
		} else {
			float tmp[16] = {
				matrix.values[0],
				matrix.values[4],
				matrix.values[8],
				matrix.values[12],
				matrix.values[1],
				matrix.values[5],
				matrix.values[9],
				matrix.values[13],
				matrix.values[2],
				matrix.values[6],
				matrix.values[10],
				matrix.values[14],
				matrix.values[3],
				matrix.values[7],
				matrix.values[11],
				matrix.values[15]
			};
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
			vec4f result;
			simd::store4f(result.x, simd::add4f(p2, p4));
			return result;
		}
	}

	constexpr mat4f& mat4f::operator+=(const mat4f& matrix) noexcept {
		if (std::is_constant_evaluated()) {
			values[0] += matrix.values[0];
			values[1] += matrix.values[1];
			values[2] += matrix.values[2];
			values[3] += matrix.values[3];
			values[4] += matrix.values[4];
			values[5] += matrix.values[5];
			values[6] += matrix.values[6];
			values[7] += matrix.values[7];
			values[8] += matrix.values[8];
			values[9] += matrix.values[9];
			values[10] += matrix.values[10];
			values[11] += matrix.values[11];
			values[12] += matrix.values[12];
			values[13] += matrix.values[13];
			values[14] += matrix.values[14];
			values[15] += matrix.values[15];
			return *this;
		} else {
			simd::reg8f ta = simd::load8f8f(values[0]);
			simd::reg8f tb = simd::load8f8f(values[8]);
			simd::reg8f ma = simd::load8f8f(matrix.values[0]);
			simd::reg8f mb = simd::load8f8f(matrix.values[8]);
			simd::store8f(values[0], simd::add8f(ta, ma));
			simd::store8f(values[8], simd::add8f(tb, mb));
			return *this;
		}
	}

	constexpr mat4f& mat4f::operator-=(const mat4f& matrix) noexcept {
		if (std::is_constant_evaluated()) {
			values[0] -= matrix.values[0];
			values[1] -= matrix.values[1];
			values[2] -= matrix.values[2];
			values[3] -= matrix.values[3];
			values[4] -= matrix.values[4];
			values[5] -= matrix.values[5];
			values[6] -= matrix.values[6];
			values[7] -= matrix.values[7];
			values[8] -= matrix.values[8];
			values[9] -= matrix.values[9];
			values[10] -= matrix.values[10];
			values[11] -= matrix.values[11];
			values[12] -= matrix.values[12];
			values[13] -= matrix.values[13];
			values[14] -= matrix.values[14];
			values[15] -= matrix.values[15];
			return *this;
		} else {
			simd::reg8f ta = simd::load8f8f(values[0]);
			simd::reg8f tb = simd::load8f8f(values[8]);
			simd::reg8f ma = simd::load8f8f(matrix.values[0]);
			simd::reg8f mb = simd::load8f8f(matrix.values[8]);
			simd::store8f(values[0], simd::sub8f(ta, ma));
			simd::store8f(values[8], simd::sub8f(tb, mb));
			return *this;
		}
	}

	constexpr mat4f& mat4f::operator*=(const mat4f& matrix) noexcept {
		if (std::is_constant_evaluated()) {
			float tmpValues[16] = {
				values[0] * matrix.values[0] + values[1] * matrix.values[4] + values[2] * matrix.values[8] + values[3] * matrix.values[12],
				values[0] * matrix.values[1] + values[1] * matrix.values[5] + values[2] * matrix.values[9] + values[3] * matrix.values[13],
				values[0] * matrix.values[2] + values[1] * matrix.values[6] + values[2] * matrix.values[10] + values[3] * matrix.values[14],
				values[0] * matrix.values[3] + values[1] * matrix.values[7] + values[2] * matrix.values[11] + values[3] * matrix.values[15],
				values[4] * matrix.values[0] + values[5] * matrix.values[4] + values[6] * matrix.values[8] + values[7] * matrix.values[12],
				values[4] * matrix.values[1] + values[5] * matrix.values[5] + values[6] * matrix.values[9] + values[7] * matrix.values[13],
				values[4] * matrix.values[2] + values[5] * matrix.values[6] + values[6] * matrix.values[10] + values[7] * matrix.values[14],
				values[4] * matrix.values[3] + values[5] * matrix.values[7] + values[6] * matrix.values[11] + values[7] * matrix.values[15],
				values[8] * matrix.values[0] + values[9] * matrix.values[4] + values[10] * matrix.values[8] + values[11] * matrix.values[12],
				values[8] * matrix.values[1] + values[9] * matrix.values[5] + values[10] * matrix.values[9] + values[11] * matrix.values[13],
				values[8] * matrix.values[2] + values[9] * matrix.values[6] + values[10] * matrix.values[10] + values[11] * matrix.values[14],
				values[8] * matrix.values[3] + values[9] * matrix.values[7] + values[10] * matrix.values[11] + values[11] * matrix.values[15],
				values[12] * matrix.values[0] + values[13] * matrix.values[4] + values[14] * matrix.values[8] + values[15] * matrix.values[12],
				values[12] * matrix.values[1] + values[13] * matrix.values[5] + values[14] * matrix.values[9] + values[15] * matrix.values[13],
				values[12] * matrix.values[2] + values[13] * matrix.values[6] + values[14] * matrix.values[10] + values[15] * matrix.values[14],
				values[12] * matrix.values[3] + values[13] * matrix.values[7] + values[14] * matrix.values[11] + values[15] * matrix.values[15]
			};
			for (uint8 i = 0; i < 16; i++) {
				values[i] = tmpValues[i];
			}
			return *this;
		} else {
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
