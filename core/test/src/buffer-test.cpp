#include <gtest/gtest.h>
#include <memory/memory.h>

using namespace spruce;

TEST(BufferTest, DefaultConstruct) {
	buffer<int32> buffer;
	EXPECT_EQ(buffer, nullptr);
	EXPECT_EQ(buffer.data, nullptr);
	EXPECT_EQ(buffer.size, 0);
}

TEST(BufferTest, SizeConstruct) {
	constexpr uint64 NUM = 4;
	buffer<int32> buffer(NUM);
	EXPECT_TRUE(buffer != nullptr);
	EXPECT_EQ(buffer.size, NUM);
	buffer.free();
	EXPECT_EQ(buffer, nullptr);
}
