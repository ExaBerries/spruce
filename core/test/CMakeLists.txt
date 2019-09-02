enable_testing()

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIR})

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(test ${SOURCE_FILES})

target_link_libraries(test PRIVATE
	spruce
	gtest
	gtest_main
)

target_compile_options(test PRIVATE
	-O3
)
