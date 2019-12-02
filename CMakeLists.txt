cmake_minimum_required(VERSION 3.8.0 FATAL_ERROR)

project(spruce VERSION 0.0.9)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${PROJECT_SOURCE_DIR}/core/include)

add_subdirectory(core)
add_subdirectory(test-project)
