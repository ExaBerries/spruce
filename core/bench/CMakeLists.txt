file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(bench ${SOURCE_FILES})

target_link_libraries(bench PRIVATE
	spruce benchmark pthread
)

target_compile_features(bench PRIVATE cxx_std_17)
