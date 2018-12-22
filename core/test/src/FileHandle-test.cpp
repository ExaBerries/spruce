#include <gtest/gtest.h>
#include <io/io.h>

using namespace spruce;

TEST(FileHandleTest, FileHandleList) {
	FileHandle folder(FileHandle::ABSOLUTE, "../core/test/assets/file-handle-list-test");
	buffer<FileHandle> subItems = folder.list();
	ASSERT_TRUE(subItems.size > 0);
	std::pair<string, bool> expectedNames[] = {
			std::pair<string, bool>("a", false),
			std::pair<string, bool>("b", false),
			std::pair<string, bool>("c", false)
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
