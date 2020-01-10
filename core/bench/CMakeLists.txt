file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(bench ${SOURCE_FILES})

target_link_libraries(bench PRIVATE
	spruce
	benchmark
)

target_compile_options(bench PRIVATE
	-O3
	-Wno-attributes
	-Wno-unknown-pragmas
)

target_include_directories(bench PRIVATE
	${CMAKE_SOURCE_DIR}/core/src
)
