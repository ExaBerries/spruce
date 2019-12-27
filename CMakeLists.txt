cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)

project(spruce VERSION 0.0.9 LANGUAGES C CXX OBJC OBJCXX)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(${PROJECT_SOURCE_DIR}/core/include)

add_subdirectory(core)
add_subdirectory(test-project)
