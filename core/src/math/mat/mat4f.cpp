#include <math/mat/mat4f.h>
#include <cstring>

namespace spruce {
	mat4f::mat4f() {
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
	}

	mat4f::mat4f(const float values[16]) {
		simd::store8f(this->values[0], simd::load8f8f(values[0]));
		simd::store8f(this->values[8], simd::load8f8f(values[8]));
	}

	mat4f::mat4f(const vec3f& translation, const quaternion& rotation, const vec3f& scale) {
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

	mat4f::mat4f(const vec3f& direction, const vec3f& up) {
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

	mat4f::mat4f(float v0, float v1, float v2, float v3, float v4, float v5, float v6, float v7, float v8, float v9, float v10, float v11, float v12, float v13, float v14, float v15) {
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

	mat4f& mat4f::setIdentity() {
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

	mat4f& mat4f::set(const float values[16]) {
		simd::store8f(this->values[0], simd::load8f8f(values[0]));
		simd::store8f(this->values[8], simd::load8f8f(values[8]));
		return *this;
	}

	mat4f& mat4f::set(const vec3f& translation, const quaternion& rotation, const vec3f& scale) {
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

	mat4f& mat4f::set(const vec3f& direction, const vec3f& up) {
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

	bool mat4f::operator==(const mat4f& matrix) const {
		for (uint8 i = 0; i < 16; i++) {
			if (values[i] != matrix.values[i]) {
				return false;
			}
		}
		return true;
	}

	bool mat4f::operator!=(const mat4f& matrix) const {
		for (uint8 i = 0; i < 16; i++) {
			if (values[i] != matrix.values[i]) {
				return true;
			}
		}
		return false;
	}

	std::ostream& operator<<(std::ostream& stream, const mat4f& matrix) {
		stream << "mat4f(";
		for (int i = 0; i < 16; i++) {
			stream << matrix.values[i] << ", ";
		}
		stream << matrix.values[15] << ")";
		return stream;
	}
}
