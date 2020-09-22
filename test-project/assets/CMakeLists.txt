function("add_shader" scene shader)
	#add_custom_target(${scene}-${shader}-shdr-dir ALL
	#	COMMAND mkdir -p ${shader}
	#)

	file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/${shader}/${shader}.gl.vert DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/${shader}/)
	file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/${shader}/${shader}.gl.frag DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/${shader}/)

	#add_custom_target(cube-${shader}-shdr-gl ALL
	#	COMMAND glslangValidator -G ${CMAKE_CURRENT_SOURCE_DIR}/${shader}/${shader}.gl.vert -o ${CMAKE_BINARY_SOURCE_DIR}/${shader}/${shader}.vert.gl.spv
	#	COMMAND glslangValidator -G ${CMAKE_CURRENT_SOURCE_DIR}/${shader}/${shader}.gl.frag -o ${CMAKE_BINARY_SOURCE_DIR}/${shader}/${shader}.frag.gl.spv
	#)

	add_custom_target(${scene}-${shader}-shdr-vk ALL
		DEPENDS ${shader}/${shader}.vert.vk.spv ${shader}/${shader}.frag.vk.spv
	)

	add_custom_command(
		OUTPUT ${shader}/${shader}.vert.vk.spv
		COMMAND glslangValidator -V100 -tm ${CMAKE_CURRENT_SOURCE_DIR}/${shader}/${shader}.vk.vert -o ${shader}/${shader}.vert.vk.spv
	)
	add_custom_command(
		OUTPUT ${shader}/${shader}.frag.vk.spv
		COMMAND glslangValidator -V100 -tm ${CMAKE_CURRENT_SOURCE_DIR}/${shader}/${shader}.vk.frag -o ${shader}/${shader}.frag.vk.spv
	)

	if(APPLE)
	file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/${shader}/${shader}.metal DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/${shader}/)
	add_custom_target(${scene}-${shader}-shdr-mtl ALL
		DEPENDS ${shader}/${shader}/.metallib
	)
	add_custom_command(
		OUTPUT ${shader}/${shader}.air
		COMMAND xcrun -sdk macosx metal ${CMAKE_CURRENT_SOURCE_DIR}/${shader}/${shader}.metal -c -o ${shader}/${shader}.air
	)
	add_custom_command(
		OUTPUT ${shader}/${shader}.metallib
		DEPENDS ${shader}/${shader}.air
		COMMAND xcrun -sdk macosx metallib ${shader}/${shader}.air -o ${shader}/${shader}.metallib
	)
	endif()
endfunction("add_shader")

add_subdirectory(basic)
add_subdirectory(cube)
add_subdirectory(bench)
