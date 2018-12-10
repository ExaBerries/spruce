include_directories(${PROJECT_SOURCE_DIR}/core/src)

find_package(Freetype REQUIRED)

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(spruce STATIC ${SOURCE_FILES})
set_target_properties(spruce PROPERTIES
	VERSION ${PROJECT_VERSION}
	OUTPUT_NAME ${PROJECT_NAME}
	LINKER_LANGUAGE CXX
)

target_include_directories(spruce
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		${FREETYPE_INCLUDE_DIRS}
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_features(spruce PRIVATE cxx_std_17)

target_compile_options(spruce PRIVATE
	-Wall
	-Wextra
	-Wshadow=local
	-pedantic
)

target_compile_definitions(spruce PRIVATE
	DEBUG
)
