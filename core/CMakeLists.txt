include_directories(${PROJECT_SOURCE_DIR}/core/src)

find_package(Freetype REQUIRED)

file(GLOB_RECURSE SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

if(APPLE) # mac
file(GLOB_RECURSE OBJC_SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.mm
)
endif()

add_library(spruce STATIC ${SOURCE_FILES} ${OBJC_SOURCE_FILES})

set_target_properties(spruce PROPERTIES
	VERSION ${PROJECT_VERSION}
	OUTPUT_NAME ${PROJECT_NAME}
	LINKER_LANGUAGE CXX
)

target_link_libraries(spruce PRIVATE
	freetype
	freeimage
)

if(APPLE) # mac
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} \
	-framework Metal\
	-framework OpenGL\
	-framework Cocoa\
	-framework Quartz\
")
endif()

if(UNIX AND NOT APPLE) # linux
target_link_libraries(spruce PRIVATE
	X11
	vulkan
	GL
	GLEW
	GLX
	pthread
)
endif()

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
	-pedantic
	-g
	-Wno-unused-parameter
	-Wno-deprecated-declarations
	-mavx2
	-mfma
)

target_compile_definitions(spruce PRIVATE
	DEBUG
)
if(APPLE) # mac
SET(CMAKE_AR llvm-ar)
SET(CMAKE_RANLIB llvm-ranlib)
endif()

add_subdirectory(test)
add_subdirectory(bench)
