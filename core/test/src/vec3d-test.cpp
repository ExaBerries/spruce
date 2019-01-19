#include <gtest/gtest.h>
#include <math/vec/vec3d.h>

using namespace spruce;

TEST(Vec3dTest, assignScalar) {
	vec3d vec = 1;
	EXPECT_EQ(vec, vec3d(1, 1, 1));
}

TEST(Vec3dTest, eq) {
	vec3d a;
	vec3d b(0, 0, 0);
	EXPECT_EQ(a, b);
}

TEST(Vec3dTest, nor) {
	vec3d a(10, 0, 0);
	vec3d b(1, 0, 0);
	a.nor();
	EXPECT_EQ(a, b);
}

TEST(Vec3dTest, mag) {
	const vec3d vec(4, 0, 0);
	EXPECT_EQ(vec.mag(), 4);
}

TEST(Vec3dTest, mag2) {
	const vec3d vec(4, 0, 0);
	EXPECT_EQ(vec.mag2(), 16);
}

TEST(Vec3dTest, addVec) {
	const vec3d a(2, 0, 2);
	const vec3d b(0, 6, -2);
	EXPECT_EQ(a + b, vec3d(2, 6, 0));
}

TEST(Vec3dTest, subVec) {
	const vec3d a(2, 0, 2);
	const vec3d b(0, 6, -2);
	EXPECT_EQ(a - b, vec3d(2, -6, 4));
}

TEST(Vec3dTest, mulScalar) {
	const vec3d a(1, 0, 0);
	const float b = 4;
	EXPECT_EQ(a * b, vec3d(a.x * b, a.y * b, a.z * b));
}

TEST(Vec3dTest, divScalar) {
	const vec3d a(8, 0, 0);
	const float b = 4;
	EXPECT_EQ(a / b, vec3d(a.x / b, a.y / b, a.z / b));
}

TEST(Vec3dTest, addEqVec) {
	vec3d a(1, 0, 0);
	const vec3d b(0, 1, 0);
	a += b;
	EXPECT_EQ(a, vec3d(1, 1, 0));
}

TEST(Vec3dTest, subEqVec) {
	vec3d a(1, 0, 0);
	const vec3d b(0, 1, 0);
	a -= b;
	EXPECT_EQ(a, vec3d(1, -1, 0));
}

TEST(Vec3dTest, addEqScalar) {
	vec3d a(1, 0, 0);
	const float b = 1;
	a += 1;
	EXPECT_EQ(a, vec3d(2, 1, 1));
}
