#include <gtest/gtest.h>
#include <math/vec/vec3f.h>

using namespace spruce;

TEST(Vec3fTest, vec3fsi) {
	vec3f vec = 1;
	EXPECT_EQ(vec, vec3f(1, 1, 1));
}

TEST(Vec3fTest, vec3feq) {
	vec3f a;
	vec3f b(0, 0, 0);
	EXPECT_EQ(a, b);
}

TEST(Vec3fTest, vec3fnor) {
	vec3f a(10, 0, 0);
	vec3f b(1, 0, 0);
	a.nor();
	EXPECT_EQ(a, b);
}

TEST(Vec3fTest, vec3fmag) {
	const vec3f vec(4, 0, 0);
	EXPECT_EQ(vec.mag(), 4);
}

TEST(Vec3fTest, vec3fmag2) {
	const vec3f vec(4, 0, 0);
	EXPECT_EQ(vec.mag2(), 16);
}

TEST(Vec3fTest, constAdd) {
	vec3f a(2, 0, 2);
	const vec3f b(0, 6, -2);
	EXPECT_EQ(a + b, vec3f(2, 6, 0));
}

TEST(Vec3fTest, vec3fScale) {
	vec3f a(1, 0, 0);
	float b = 4;
	EXPECT_EQ(a * b, vec3f(a.x * b, a.y * b, a.z * b));
}
