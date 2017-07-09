#include "mat4f.h"

namespace spruce {
	mat4f::mat4f() {
		values[0] = 1.0;
		values[5] = 1.0;
		values[10] = 1.0;
		values[15] = 1.0;
	}

	mat4f::mat4f(float values[16]) {
		for (int i = 0; i < 16; i++) {
			this->values[i] = values[i];
		}
	}

	mat4f::mat4f(vec3f& translation, quaternion& rotation, vec3f& scale) {
		float x2 = rotation.x * rotation.x;
		float y2 = rotation.y * rotation.y;
		float z2 = rotation.z * rotation.z;
		float wx = rotation.w * rotation.x;
		float wy = rotation.w * rotation.y;
		float wz = rotation.w * rotation.z;
		values[0] = scale.x * (1.0 - y2 * 2.0 + z2 * 2.0);
		values[1] = scale.y * (rotation.x * rotation.y * 2.0 - wz);
		values[2] = scale.z * (rotation.x * rotation.z * 2.0 + wy);
		values[3] = translation.x;
		values[4] = scale.x * (rotation.x * rotation.y * 2.0 + wz);
		values[5] = scale.y * (1.0 - (x2 * 2.0 + z2 * 2.0));
		values[6] = scale.z * (rotation.y * rotation.z * 2.0 - wx);
		values[7] = translation.y;
		values[8] = scale.x * (rotation.x * rotation.z * 2.0 - wy);
		values[9] = scale.y * (rotation.y * rotation.z * 2.0 + wx);
		values[10] = scale.z * (1.0 - (x2 * 2.0 + y2 * 2.0));
		values[11] = translation.z;
		values[12] = 0.0f;
		values[13] = 0.0f;
		values[14] = 0.0f;
		values[15] = 1.0f;
	}

	mat4f::mat4f(float& near, float& far, float& fov, float& aspectRatio) {
		float fd = (float) (1.0 / tan(fov) / 2.0);
		values[0] = fd / aspectRatio;
		values[1] = 0;
		values[2] = 0;
		values[3] = 0;
		values[4] = 0;
		values[5] = fd;
		values[6] = 0;
		values[7] = 0;
		values[8] = 0;
		values[9] = 0;
		values[10] = (far + near) / (near - far);
		values[11] = -1;
		values[12] = 0;
		values[13] = 0;
		values[14] = (2 * far * near) / (near - far);
		values[15] = 0;
	}

	mat4f::~mat4f() {
	}

	mat4f operator+(mat4f left, mat4f right) {
		float values[16];
		values[0] = left.values[0] + right.values[0];
		values[1] = left.values[1] + right.values[1];
		values[2] = left.values[2] + right.values[2];
		values[3] = left.values[3] + right.values[3];
		values[4] = left.values[4] + right.values[4];
		values[5] = left.values[5] + right.values[5];
		values[6] = left.values[6] + right.values[6];
		values[7] = left.values[7] + right.values[7];
		values[8] = left.values[8] + right.values[8];
		values[9] = left.values[9] + right.values[9];
		values[10] = left.values[10] + right.values[10];
		values[11] = left.values[11] + right.values[11];
		values[12] = left.values[12] + right.values[12];
		values[13] = left.values[13] + right.values[13];
		values[14] = left.values[14] + right.values[14];
		values[15] = left.values[15] + right.values[15];
		return mat4f(values);
	}

	mat4f operator-(mat4f left, mat4f right) {
		float values[16];
		values[0] = left.values[0] - right.values[0];
		values[1] = left.values[1] - right.values[1];
		values[2] = left.values[2] - right.values[2];
		values[3] = left.values[3] - right.values[3];
		values[4] = left.values[4] - right.values[4];
		values[5] = left.values[5] - right.values[5];
		values[6] = left.values[6] - right.values[6];
		values[7] = left.values[7] - right.values[7];
		values[8] = left.values[8] - right.values[8];
		values[9] = left.values[9] - right.values[9];
		values[10] = left.values[10] - right.values[10];
		values[11] = left.values[11] - right.values[11];
		values[12] = left.values[12] - right.values[12];
		values[13] = left.values[13] - right.values[13];
		values[14] = left.values[14] - right.values[14];
		values[15] = left.values[15] - right.values[15];
		return mat4f(values);
	}

	mat4f operator*(mat4f left, mat4f right) {
		float values[16];
		values[0] = left.values[0] * right.values[0] + left.values[4] * right.values[1] + left.values[8] * right.values[2] + left.values[12] * right.values[3];
		values[1] = left.values[0] * right.values[4] + left.values[4] * right.values[5] + left.values[8] * right.values[6] + left.values[12] * right.values[7];
		values[2] = left.values[0] * right.values[8] + left.values[4] * right.values[9] + left.values[8] * right.values[10] + left.values[12] * right.values[11];
		values[3] = left.values[0] * right.values[12] + left.values[4] * right.values[13] + left.values[8] * right.values[14] + left.values[12] * right.values[15];
		values[4] = left.values[1] * right.values[0] + left.values[5] * right.values[1] + left.values[9] * right.values[2] + left.values[13] * right.values[3];
		values[5] = left.values[1] * right.values[4] + left.values[5] * right.values[5] + left.values[9] * right.values[6] + left.values[13] * right.values[7];
		values[6] = left.values[1] * right.values[8] + left.values[5] * right.values[9] + left.values[9] * right.values[10] + left.values[13] * right.values[11];
		values[7] = left.values[1] * right.values[12] + left.values[5] * right.values[13] + left.values[9] * right.values[14] + left.values[13] * right.values[15];
		values[8] = left.values[2] * right.values[0] + left.values[6] * right.values[1] + left.values[10] * right.values[2] + left.values[14] * right.values[3];
		values[9] = left.values[2] * right.values[4] + left.values[6] * right.values[5] + left.values[10] * right.values[6] + left.values[14] * right.values[7];
		values[10] = left.values[2] * right.values[8] + left.values[6] * right.values[9] + left.values[10] * right.values[10] + left.values[14] * right.values[11];
		values[11] = left.values[2] * right.values[12] + left.values[6] * right.values[13] + left.values[10] * right.values[14] + left.values[14] * right.values[15];
		values[12] = left.values[3] * right.values[0] + left.values[7] * right.values[1] + left.values[11] * right.values[2] + left.values[15] * right.values[3];
		values[13] = left.values[3] * right.values[4] + left.values[7] * right.values[5] + left.values[11] * right.values[6] + left.values[15] * right.values[7];
		values[14] = left.values[3] * right.values[8] + left.values[7] * right.values[9] + left.values[11] * right.values[10] + left.values[15] * right.values[11];
		values[15] = left.values[3] * right.values[12] + left.values[7] * right.values[13] + left.values[11] * right.values[14] + left.values[15] * right.values[15];
		return mat4f(values);
	}

	mat4f& mat4f::operator+=(const mat4f& matrix) {
			this->values[0] += matrix.values[0];
			this->values[1] += matrix.values[1];
			this->values[2] += matrix.values[2];
			this->values[3] += matrix.values[3];
			this->values[4] += matrix.values[4];
			this->values[5] += matrix.values[5];
			this->values[6] += matrix.values[6];
			this->values[7] += matrix.values[7];
			this->values[8] += matrix.values[8];
			this->values[9] += matrix.values[9];
			this->values[10] += matrix.values[10];
			this->values[11] += matrix.values[11];
			this->values[12] += matrix.values[12];
			this->values[13] += matrix.values[13];
			this->values[14] += matrix.values[14];
			this->values[15] += matrix.values[15];
			return *this;
		}

		mat4f& mat4f::operator-=(const mat4f& matrix) {
			this->values[0] -= matrix.values[0];
			this->values[1] -= matrix.values[1];
			this->values[2] -= matrix.values[2];
			this->values[3] -= matrix.values[3];
			this->values[4] -= matrix.values[4];
			this->values[5] -= matrix.values[5];
			this->values[6] -= matrix.values[6];
			this->values[7] -= matrix.values[7];
			this->values[8] -= matrix.values[8];
			this->values[9] -= matrix.values[9];
			this->values[10] -= matrix.values[10];
			this->values[11] -= matrix.values[11];
			this->values[12] -= matrix.values[12];
			this->values[13] -= matrix.values[13];
			this->values[14] -= matrix.values[14];
			this->values[15] -= matrix.values[15];
			return *this;
		}

		mat4f& mat4f::operator*=(const mat4f& matrix) {
			float values[16];
			values[0] = this->values[0] * matrix.values[0] + this->values[4] * matrix.values[1] + this->values[8] * matrix.values[2] + this->values[12] * matrix.values[3];
			values[1] = this->values[0] * matrix.values[4] + this->values[4] * matrix.values[5] + this->values[8] * matrix.values[6] + this->values[12] * matrix.values[7];
			values[2] = this->values[0] * matrix.values[8] + this->values[4] * matrix.values[9] + this->values[8] * matrix.values[10] + this->values[12] * matrix.values[11];
			values[3] = this->values[0] * matrix.values[12] + this->values[4] * matrix.values[13] + this->values[8] * matrix.values[14] + this->values[12] * matrix.values[15];
			values[4] = this->values[1] * matrix.values[0] + this->values[5] * matrix.values[1] + this->values[9] * matrix.values[2] + this->values[13] * matrix.values[3];
			values[5] = this->values[1] * matrix.values[4] + this->values[5] * matrix.values[5] + this->values[9] * matrix.values[6] + this->values[13] * matrix.values[7];
			values[6] = this->values[1] * matrix.values[8] + this->values[5] * matrix.values[9] + this->values[9] * matrix.values[10] + this->values[13] * matrix.values[11];
			values[7] = this->values[1] * matrix.values[12] + this->values[5] * matrix.values[13] + this->values[9] * matrix.values[14] + this->values[13] * matrix.values[15];
			values[8] = this->values[2] * matrix.values[0] + this->values[6] * matrix.values[1] + this->values[10] * matrix.values[2] + this->values[14] * matrix.values[3];
			values[9] = this->values[2] * matrix.values[4] + this->values[6] * matrix.values[5] + this->values[10] * matrix.values[6] + this->values[14] * matrix.values[7];
			values[10] = this->values[2] * matrix.values[8] + this->values[6] * matrix.values[9] + this->values[10] * matrix.values[10] + this->values[14] * matrix.values[11];
			values[11] = this->values[2] * matrix.values[12] + this->values[6] * matrix.values[13] + this->values[10] * matrix.values[14] + this->values[14] * matrix.values[15];
			values[12] = this->values[3] * matrix.values[0] + this->values[7] * matrix.values[1] + this->values[11] * matrix.values[2] + this->values[15] * matrix.values[3];
			values[13] = this->values[3] * matrix.values[4] + this->values[7] * matrix.values[5] + this->values[11] * matrix.values[6] + this->values[15] * matrix.values[7];
			values[14] = this->values[3] * matrix.values[8] + this->values[7] * matrix.values[9] + this->values[11] * matrix.values[10] + this->values[15] * matrix.values[11];
			values[15] = this->values[3] * matrix.values[12] + this->values[7] * matrix.values[13] + this->values[11] * matrix.values[14] + this->values[15] * matrix.values[15];
			for (int i = 0; i < 16; i++) {
				this->values[i] = values[i];
			}
			return *this;
		}
}
