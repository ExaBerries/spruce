#include <math/quaternion.h>

namespace spruce {
	quaternion::quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {
	}

	quaternion::quaternion(float pitch, float yaw, float roll) {
		float sy = sin(yaw / 2.0f);
		float sp = sin(pitch / 2.0f);
		float sr = sin(roll / 2.0f);
		float cy = cos(yaw / 2.0f);
		float cp = cos(pitch / 2.0f);
		float cr = cos(roll / 2.0f);
		x = cy * sp * cr + sy * cp * sr;
		y = sy * cp * cr - cy * sp * sr;
		z = cy * cp * sr - sy * sp * cr;
		w = cy * cp * cr + sy * sp * sr;
		nor();
	}

	quaternion::quaternion(const vec3f& a, const vec3f& b) {
		vec3f crs = vec3f(a).crs(b);
		this->x = crs.x;
		this->y = crs.y;
		this->z = crs.z;
		this->w = (a.mag() * b.mag()) + a.dot(b);
		nor();
	}

	quaternion::quaternion(const vec3f& axis, const float& angle) {
		float sinHalfAngle = sin(angle / 2.0f);
		this->x = axis.x * sinHalfAngle;
		this->y = axis.y * sinHalfAngle;
		this->z = axis.z * sinHalfAngle;
		this->w = cos(angle / 2.0f);
		nor();
	}

	quaternion& quaternion::set(const quaternion& quaternion) {
		this->x = quaternion.x;
		this->y = quaternion.y;
		this->z = quaternion.z;
		this->w = quaternion.w;
		return *this;
	}

	quaternion& quaternion::set(float x, float y, float z, float w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
		return *this;
	}

	quaternion& quaternion::set(const vec3f& axis, float angle) {
		float sinHalfAngle = sin(angle / 2.0f);
		this->x = axis.x * sinHalfAngle;
		this->y = axis.y * sinHalfAngle;
		this->z = axis.z * sinHalfAngle;
		this->w = cos(angle / 2.0f);
		nor();
		return *this;
	}

	quaternion& quaternion::set(const vec3f& a, const vec3f& b) {
		vec3f crs = vec3f(a).crs(b);
		this->x = crs.x;
		this->y = crs.y;
		this->z = crs.z;
		this->w = (a.mag() * b.mag()) + a.dot(b);
		nor();
		return *this;
	}

	quaternion& quaternion::set(float yaw, float pitch, float roll) {
		float sy = sin(yaw / 2.0f);
		float sp = sin(pitch / 2.0f);
		float sr = sin(roll / 2.0f);
		float cy = cos(yaw / 2.0f);
		float cp = cos(pitch / 2.0f);
		float cr = cos(roll / 2.0f);
		x = cy * sp * cr + sy * cp * sr;
		y = sy * cp * cr - cy * sp * sr;
		z = cy * cp * sr - sy * sp * cr;
		w = cy * cp * cr + sy * sp * sr;
		nor();
		return *this;
	}

	void quaternion::toEuler(float& yaw, float& pitch, float& roll) {
		float t = y * x + z * w;
		int8 pole = t > 0.499f ? 1 : (t < -0.499f ? -1 : 0);
		bool locked = !(pole == 0);
		yaw = !locked ? atan2(2.0f * (y * w + x * z), 1.0f - 2.0f * (y * y + x * x)) : 0.0f;
		pitch = !locked ? asin(2.0f * (w * x - z * y)) : pole * static_cast<float>(M_PI) * 0.5f;
		roll = !locked ? atan2(2.0f * (w * z + y * x), 1.0f - 2.0f * (x * x + z * z)) : pole * 2.0f * atan2(y, w);
	}

	float quaternion::mag2() const {
		return x * x + y * y + z * z + w * w;
	}

	float quaternion::mag() const {
		return sqrt(mag2());
	}

	quaternion& quaternion::conjugate() {
		x = -x;
		y = -y;
		z = -z;
		return *this;
	}

	float quaternion::dot(const quaternion& quaternion) const {
		return x * quaternion.x + y * quaternion.y + z * quaternion.z + w * quaternion.w;
	}

	std::ostream& operator<<(std::ostream& stream, const quaternion& quaternion) {
		stream << "quaternion(" << quaternion.x << ", " << quaternion.y << ", " << quaternion.z << ", " << quaternion.w << ")";
		return stream;
	}

	quaternion quaternion::lerp(const quaternion& a, const quaternion& b, float alpha) {
		return {(1.0f - alpha) * a.x + alpha * b.x, (1.0f - alpha) * a.y + alpha * b.y, (1.0f - alpha) * a.z + alpha * b.z, (1.0f - alpha) * a.w + alpha * b.w};
	}
}
