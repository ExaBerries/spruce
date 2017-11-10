#include <math/mat4f.h>

namespace spruce {
	mat4f::mat4f() {
		values[0] = 1.0;
		values[1] = 0.0;
		values[2] = 0.0;
		values[3] = 0.0;
		values[4] = 0.0;
		values[5] = 1.0;
		values[6] = 0.0;
		values[7] = 0.0;
		values[8] = 0.0;
		values[9] = 0.0;
		values[10] = 1.0;
		values[11] = 0.0;
		values[12] = 0.0;
		values[13] = 0.0;
		values[14] = 0.0;
		values[15] = 1.0;
	}

	mat4f::mat4f(float values[16]) {
		for (uint8 i = 0; i < 16; i++) {
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
		float size = 1.0 / tan(fov / 2.0);
		values[0] = size / aspectRatio;
		values[1] = 0.0;
		values[2] = 0.0;
		values[3] = 0.0;
		values[4] = 0.0;
		values[5] = size;
		values[6] = 0.0;
		values[7] = 0.0;
		values[8] = 0.0;
		values[9] = 0.0;
		values[10] = (far + near) / (near - far);
		values[11] = -1.0;
		values[12] = 0.0;
		values[13] = 0.0;
		values[14] = (2.0 * far * near) / (near - far);
		values[15] = 0.0;
	}

	mat4f::mat4f(vec3f& direction, vec3f& up) {
		vec3f dirNor = vec3f(direction).nor();
		vec3f dirCrsUp = vec3f(dirNor).crs(up).nor();
		vec3f dirCrsUpCrsDir = vec3f(dirCrsUp).crs(dirNor).nor();
		values[0] = dirCrsUp.x;
		values[1] = dirCrsUpCrsDir.x;
		values[2] = -dirNor.x;
		values[3] = 0;
		values[4] = dirCrsUp.y;
		values[5] = dirCrsUpCrsDir.y;
		values[6] = -dirNor.y;
		values[7] = 0;
		values[8] = dirCrsUp.z;
		values[9] = dirCrsUpCrsDir.z;
		values[10] = -dirNor.z;
		values[11] = 0;
		values[12] = 0;
		values[13] = 0;
		values[14] = 0;
		values[15] = 1;
	}

	mat4f::mat4f(float left, float right, float top, float bottom, float near, float far) {
		float x = 2 / (right - left);
		float y = 2 / (top - bottom);
		float z = 2 / (far - near);
		float tx = -(right + left) / (right - left);
		float ty = -(top + bottom) / (top - bottom);
		float tz = -(far + near) / (far - near);
		values[0] = x;
		values[1] = 0;
		values[2] = 0;
		values[3] = 0;
		values[4] = 0;
		values[5] = y;
		values[6] = 0;
		values[7] = 0;
		values[8] = 0;
		values[9] = 0;
		values[10] = z;
		values[11] = 0;
		values[12] = tx;
		values[13] = ty;
		values[14] = tz;
		values[15] = 1;
	}

	mat4f::mat4f(const mat4f& matrix) {
		for (uint8 i = 0; i < 16; i++) {
			values[i] = matrix.values[i];
		}
	}

	mat4f::~mat4f() {
	}

	mat4f& mat4f::setIdentity() {
		values[0] = 1.0;
		values[1] = 0.0;
		values[2] = 0.0;
		values[3] = 0.0;
		values[4] = 0.0;
		values[5] = 1.0;
		values[6] = 0.0;
		values[7] = 0.0;
		values[8] = 0.0;
		values[9] = 0.0;
		values[10] = 1.0;
		values[11] = 0.0;
		values[12] = 0.0;
		values[13] = 0.0;
		values[14] = 0.0;
		values[15] = 1.0;
		return *this;
	}

	mat4f& mat4f::set(float values[16]) {
		for (int i = 0; i < 16; i++) {
			this->values[i] = values[i];
		}
		return *this;
	}

	mat4f& mat4f::set(vec3f& translation, quaternion& rotation, vec3f& scale) {
		float x2 = rotation.x * rotation.x;
		float y2 = rotation.y * rotation.y;
		float z2 = rotation.z * rotation.z;
		float wx = rotation.w * rotation.x;
		float wy = rotation.w * rotation.y;
		float wz = rotation.w * rotation.z;
		values[0] = scale.x * (1.0 - (y2 * 2.0 + z2 * 2.0));
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
		return *this;
	}

	mat4f& mat4f::set(float& near, float& far, float& fov, float& aspectRatio) {
		float size = 1.0 / atan(fov / 2.0);
		values[0] = size / aspectRatio;
		values[1] = 0.0;
		values[2] = 0.0;
		values[3] = 0.0;
		values[4] = 0.0;
		values[5] = size;
		values[6] = 0.0;
		values[7] = 0.0;
		values[8] = 0.0;
		values[9] = 0.0;
		values[10] = (far + near) / (near - far);
		values[11] = (2.0 * far * near) / (near - far);
		values[12] = 0.0;
		values[13] = 0.0;
		values[14] = -1.0;
		values[15] = 0.0;
		return *this;
	}

	mat4f& mat4f::set(vec3f& direction, vec3f& up) {
		vec3f dirNor = vec3f(direction).nor();
		vec3f dirCrsUp = vec3f(dirNor).crs(up).nor();
		vec3f dirCrsUpCrsDir = vec3f(dirCrsUp).crs(dirNor).nor();
		values[0] = dirCrsUp.x;
		values[1] = dirCrsUp.y;
		values[2] = dirCrsUp.z;
		values[3] = 0;
		values[4] = dirCrsUpCrsDir.x;
		values[5] = dirCrsUpCrsDir.y;
		values[6] = dirCrsUpCrsDir.z;
		values[7] = 0;
		values[8] = -dirNor.x;
		values[9] = -dirNor.y;
		values[10] = -dirNor.z;
		values[11] = 0;
		values[12] = 0;
		values[13] = 0;
		values[14] = 0;
		values[15] = 1;
		return *this;
	}

	mat4f& mat4f::set(float left, float right, float top, float bottom, float near, float far) {
		float x = 2 / (right - left);
		float y = 2 / (top - bottom);
		float z = 2 / (far - near);
		float tx = -(right + left) / (right - left);
		float ty = -(top + bottom) / (top - bottom);
		float tz = -(far + near) / (far - near);
		values[0] = x;
		values[1] = 0;
		values[2] = 0;
		values[3] = 0;
		values[4] = 0;
		values[5] = y;
		values[6] = 0;
		values[7] = 0;
		values[8] = 0;
		values[9] = 0;
		values[10] = z;
		values[11] = 0;
		values[12] = tx;
		values[13] = ty;
		values[14] = tz;
		values[15] = 1;
		return *this;
	}

	float mat4f::determinate() {
		float a = values[0] * (values[5] * (values[10] * values[15] - values[11] * values[14]) - values[6] * (values[9] * values[15] - values[11] * values[13]) + values[7] * (values[9] * values[14] - values[10] * values[13]));
		float b = values[1] * (values[4] * (values[10] * values[15] - values[11] * values[14]) - values[6] * (values[8] * values[15] - values[11] * values[12]) + values[7] * (values[8] * values[14] - values[10] * values[12]));
		float c = values[2] * (values[4] * (values[9] * values[15] - values[11] * values[13]) - values[5] * (values[8] * values[15] - values[11] * values[12]) + values[7] * (values[8] * values[13] - values[9] * values[12]));
		float d = values[3] * (values[4] * (values[9] * values[14] - values[10] * values[13]) - values[5] * (values[8] * values[14] - values[10] * values[12]) + values[6] * (values[8] * values[13] - values[9] * values[12]));
		return a - b + c - d;
	}

	mat4f& mat4f::invert() {
		return *this;
	}

	mat4f& mat4f::transpose() {
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

	mat4f operator+(const mat4f& left, const mat4f& right) {
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

	mat4f operator-(const mat4f& left, const mat4f& right) {
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

	mat4f operator*(const mat4f& left, const mat4f& right) {
		float values[16];
		values[0] = left.values[0] * right.values[0] + left.values[1] * right.values[4] + left.values[2] * right.values[8] + left.values[3] * right.values[12];
		values[1] = left.values[0] * right.values[1] + left.values[1] * right.values[5] + left.values[2] * right.values[9] + left.values[3] * right.values[13];
		values[2] = left.values[0] * right.values[2] + left.values[1] * right.values[6] + left.values[2] * right.values[10] + left.values[3] * right.values[14];
		values[3] = left.values[0] * right.values[3] + left.values[1] * right.values[7] + left.values[2] * right.values[11] + left.values[3] * right.values[15];
		values[4] = left.values[4] * right.values[0] + left.values[5] * right.values[4] + left.values[6] * right.values[8] + left.values[7] * right.values[12];
		values[5] = left.values[4] * right.values[1] + left.values[5] * right.values[5] + left.values[6] * right.values[9] + left.values[7] * right.values[13];
		values[6] = left.values[4] * right.values[2] + left.values[5] * right.values[6] + left.values[6] * right.values[10] + left.values[7] * right.values[14];
		values[7] = left.values[4] * right.values[3] + left.values[5] * right.values[7] + left.values[6] * right.values[11] + left.values[7] * right.values[15];
		values[8] = left.values[8] * right.values[0] + left.values[9] * right.values[4] + left.values[10] * right.values[8] + left.values[11] * right.values[12];
		values[9] = left.values[8] * right.values[1] + left.values[9] * right.values[5] + left.values[10] * right.values[9] + left.values[11] * right.values[13];
		values[10] = left.values[8] * right.values[2] + left.values[9] * right.values[6] + left.values[10] * right.values[10] + left.values[11] * right.values[14];
		values[11] = left.values[8] * right.values[3] + left.values[9] * right.values[7] + left.values[10] * right.values[11] + left.values[11] * right.values[15];
		values[12] = left.values[12] * right.values[0] + left.values[13] * right.values[4] + left.values[14] * right.values[8] + left.values[15] * right.values[12];
		values[13] = left.values[12] * right.values[1] + left.values[13] * right.values[5] + left.values[14] * right.values[9] + left.values[15] * right.values[13];
		values[14] = left.values[12] * right.values[2] + left.values[13] * right.values[6] + left.values[14] * right.values[10] + left.values[15] * right.values[14];
		values[15] = left.values[12] * right.values[3] + left.values[13] * right.values[7] + left.values[14] * right.values[11] + left.values[15] * right.values[15];
		return mat4f(values);
	}

	vec3f operator*(const vec3f& vector, const mat4f& matrix) {
		float x = vector.x * matrix.values[0] + vector.y * matrix.values[4] + vector.z * matrix.values[8] + matrix.values[12];
		float y = vector.x * matrix.values[1] + vector.y * matrix.values[5] + vector.z * matrix.values[9] + matrix.values[13];
		float z = vector.x * matrix.values[2] + vector.y * matrix.values[6] + vector.z * matrix.values[10] + matrix.values[14];
		return vec3f(x, y, z);
	}

	vec3f operator*(const mat4f& matrix, const vec3f& vector) {
		float x = vector.x * matrix.values[0] + vector.y * matrix.values[4] + vector.z * matrix.values[8] + matrix.values[12];
		float y = vector.x * matrix.values[1] + vector.y * matrix.values[5] + vector.z * matrix.values[9] + matrix.values[13];
		float z = vector.x * matrix.values[2] + vector.y * matrix.values[6] + vector.z * matrix.values[10] + matrix.values[14];
		return vec3f(x, y, z);
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
		values[0] = this->values[0] * matrix.values[0] + this->values[1] * matrix.values[4] + this->values[2] * matrix.values[8] + this->values[3] * matrix.values[12];
		values[1] = this->values[0] * matrix.values[1] + this->values[1] * matrix.values[5] + this->values[2] * matrix.values[9] + this->values[3] * matrix.values[13];
		values[2] = this->values[0] * matrix.values[2] + this->values[1] * matrix.values[6] + this->values[2] * matrix.values[10] + this->values[3] * matrix.values[14];
		values[3] = this->values[0] * matrix.values[3] + this->values[1] * matrix.values[7] + this->values[2] * matrix.values[11] + this->values[3] * matrix.values[15];
		values[4] = this->values[4] * matrix.values[0] + this->values[5] * matrix.values[4] + this->values[6] * matrix.values[8] + this->values[7] * matrix.values[12];
		values[5] = this->values[4] * matrix.values[1] + this->values[5] * matrix.values[5] + this->values[6] * matrix.values[9] + this->values[7] * matrix.values[13];
		values[6] = this->values[4] * matrix.values[2] + this->values[5] * matrix.values[6] + this->values[6] * matrix.values[10] + this->values[7] * matrix.values[14];
		values[7] = this->values[4] * matrix.values[3] + this->values[5] * matrix.values[7] + this->values[6] * matrix.values[11] + this->values[7] * matrix.values[15];
		values[8] = this->values[8] * matrix.values[0] + this->values[9] * matrix.values[4] + this->values[10] * matrix.values[8] + this->values[11] * matrix.values[12];
		values[9] = this->values[8] * matrix.values[1] + this->values[9] * matrix.values[5] + this->values[10] * matrix.values[9] + this->values[11] * matrix.values[13];
		values[10] = this->values[8] * matrix.values[2] + this->values[9] * matrix.values[6] + this->values[10] * matrix.values[10] + this->values[11] * matrix.values[14];
		values[11] = this->values[8] * matrix.values[3] + this->values[9] * matrix.values[7] + this->values[10] * matrix.values[11] + this->values[11] * matrix.values[15];
		values[12] = this->values[12] * matrix.values[0] + this->values[13] * matrix.values[4] + this->values[14] * matrix.values[8] + this->values[15] * matrix.values[12];
		values[13] = this->values[12] * matrix.values[1] + this->values[13] * matrix.values[5] + this->values[14] * matrix.values[9] + this->values[15] * matrix.values[13];
		values[14] = this->values[12] * matrix.values[2] + this->values[13] * matrix.values[6] + this->values[14] * matrix.values[10] + this->values[15] * matrix.values[14];
		values[15] = this->values[12] * matrix.values[3] + this->values[13] * matrix.values[7] + this->values[14] * matrix.values[11] + this->values[15] * matrix.values[15];
		memcpy(this->values, values, sizeof(float) * 16);
		return *this;
	}

	std::ostream& operator<<(std::ostream& stream, const mat4f& matrix) {
		stream << "mat4f(";
		for (int i = 0; i < 15; i++) {
			stream << matrix.values[i] << ", ";
		}
		stream << matrix.values[15] << ")";
		return stream;
	}
}
