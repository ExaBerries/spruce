include_directories(${PROJECT_SOURCE_DIR}/src)

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(spruce-test ${SOURCE_FILES})

target_link_libraries(spruce-test PRIVATE
	spruce
)

target_include_directories(spruce-test PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_options(spruce-test PRIVATE
	-Wall
	-Wextra
	-Wshadow
	-Wpedantic
	-Wno-unused-parameter
	-Wno-unknown-pragmas
)

target_include_directories(spruce-test PRIVATE
	${CMAKE_SOURCE_DIR}/core/src
)

add_subdirectory(assets)
