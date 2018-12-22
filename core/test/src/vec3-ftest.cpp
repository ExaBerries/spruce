#include <gtest/gtest.h>
#include <math/vec/vec3f.h>

using namespace spruce;

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
