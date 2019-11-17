#[[add_custom_target(basic-default-shdr-gl ALL
	COMMAND glslangValidator -G ${CMAKE_CURRENT_SOURCE_DIR}/default/default.gl.vert -o default/default.vert.gl.spv
	COMMAND glslangValidator -G ${CMAKE_CURRENT_SOURCE_DIR}/default/default.gl.vert -o default/default.vert.gl.spv
)

add_custom_target(basic-default-shdr-vk ALL
	COMMAND glslangValidator -V100 -tm ${CMAKE_CURRENT_SOURCE_DIR}/default/default.vk.vert -o default/default.vert.vk.spv
	COMMAND glslangValidator -V100 -tm ${CMAKE_CURRENT_SOURCE_DIR}/default/default.vk.vert -o default/default.vert.vk.spv
)

if(APPLE)
add_custom_target(basic-default-shdr-mtl ALL
	COMMAND xcrun -sdk macosx metal ${CMAKE_CURRENT_SOURCE_DIR}/default/default.metal -o default/default.air
	COMMAND xcrun -sdk macosx metallib ${CMAKE_CURRENT_SOURCE_DIR}/default/default.air -o default/default.metallib
)
endif()]]#
