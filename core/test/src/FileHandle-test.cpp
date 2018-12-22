#include <gtest/gtest.h>
#include <io/io.h>

using namespace spruce;

TEST(FileHandleTest, FileHandleList) {
	FileHandle folder(FileHandle::ABSOLUTE, "../core/test/assets/file-handle-list-test");
	buffer<FileHandle> subItems = folder.list();
	ASSERT_TRUE(subItems.size > 0);
	std::pair<string, bool> expectedNames[] = {
			std::pair("a", false),
			std::pair("b", false),
			std::pair("c", false)
	};
	for (FileHandle& file : subItems) {
		bool found = false;
		for (auto& [name, found] : expectedNames) {
			if (name == file.name) {
				found = true;
			}
		}
	}
	for (auto& [name, found] : expectedNames) {
		EXPECT_TRUE(found);
	}
}
