#include <gtest/gtest.h>
#include <math/vec/vec3f.h>

using namespace spruce;

TEST(Vec3fTest, assignScalar) {
	vec3f vec = 1;
	EXPECT_EQ(vec, vec3f(1, 1, 1));
}

TEST(Vec3fTest, eq) {
	vec3f a;
	vec3f b(0, 0, 0);
	EXPECT_EQ(a, b);
}

TEST(Vec3fTest, nor) {
	vec3f a(10, 0, 0);
	vec3f b(1, 0, 0);
	a.nor();
	EXPECT_EQ(a, b);
}

TEST(Vec3fTest, mag) {
	const vec3f vec(4, 0, 0);
	EXPECT_EQ(vec.mag(), 4);
}

TEST(Vec3fTest, mag2) {
	const vec3f vec(4, 0, 0);
	EXPECT_EQ(vec.mag2(), 16);
}

TEST(Vec3fTest, addVec) {
	const vec3f a(2, 0, 2);
	const vec3f b(0, 6, -2);
	EXPECT_EQ(a + b, vec3f(2, 6, 0));
}

TEST(Vec3fTest, subVec) {
	const vec3f a(2, 0, 2);
	const vec3f b(0, 6, -2);
	EXPECT_EQ(a - b, vec3f(2, -6, 4));
}

TEST(Vec3fTest, mulScalar) {
	const vec3f a(1, 0, 0);
	const float b = 4;
	EXPECT_EQ(a * b, vec3f(a.x * b, a.y * b, a.z * b));
}

TEST(Vec3fTest, divScalar) {
	const vec3f a(8, 0, 0);
	const float b = 4;
	EXPECT_EQ(a / b, vec3f(a.x / b, a.y / b, a.z / b));
}

TEST(Vec3fTest, addEqVec) {
	vec3f a(1, 0, 0);
	const vec3f b(0, 1, 0);
	a += b;
	EXPECT_EQ(a, vec3f(1, 1, 0));
}

TEST(Vec3fTest, subEqVec) {
	vec3f a(1, 0, 0);
	const vec3f b(0, 1, 0);
	a -= b;
	EXPECT_EQ(a, vec3f(1, -1, 0));
}

TEST(Vec3fTest, addEqScalar) {
	vec3f a(1, 0, 0);
	const float b = 1;
	a += 1;
	EXPECT_EQ(a, vec3f(2, 1, 1));
}
