#include <catch2/catch.hpp>
#include <io/io.h>

namespace spruce {
	namespace io {
		namespace test {
			TEST_CASE("FileHandle.list") {
				FileHandle folder(FileHandle::ABSOLUTE, "../core/test/assets/file-handle-list-test");
				buffer<FileHandle> subItems = folder.list();
				REQUIRE(subItems.size > 0);
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
					REQUIRE(found);
				}
			}
		}
	}
}
