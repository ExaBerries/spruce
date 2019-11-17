add_custom_target(default-shdr-dir ALL
	COMMAND mkdir -p default
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/default/default.gl.vert DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/default/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/default/default.gl.frag DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/default/)

#add_custom_target(basic-default-shdr-gl ALL
#	COMMAND glslangValidator -G ${CMAKE_CURRENT_SOURCE_DIR}/default/default.gl.vert -o ${CMAKE_BINARY_SOURCE_DIR}/default/default.vert.gl.spv
#	COMMAND glslangValidator -G ${CMAKE_CURRENT_SOURCE_DIR}/default/default.gl.frag -o ${CMAKE_BINARY_SOURCE_DIR}/default/default.frag.gl.spv
#)

add_custom_target(basic-default-shdr-vk ALL
	COMMAND glslangValidator -V100 -tm ${CMAKE_CURRENT_SOURCE_DIR}/default/default.vk.vert -o default/default.vert.vk.spv
	COMMAND glslangValidator -V100 -tm ${CMAKE_CURRENT_SOURCE_DIR}/default/default.vk.frag -o default/default.frag.vk.spv
)

if(APPLE)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/default/default.metal DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/default/)
add_custom_target(basic-default-shdr-mtl ALL
	COMMAND xcrun -sdk macosx metal ${CMAKE_CURRENT_SOURCE_DIR}/default/default.metal -c -o default/default.air
	COMMAND xcrun -sdk macosx metallib default/default.air -o default/default.metallib
)
endif()