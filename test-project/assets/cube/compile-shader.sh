function createShader {
	#glslangValidator -G $1/$1.gl.vert -o $1/$1.vert.gl.spv
	#glslangValidator -G $1/$1.gl.frag -o $1/$1.frag.gl.spv
	glslangValidator -V100 -tm $1/$1.vk.vert -o $1/$1.vert.vk.spv
	glslangValidator -V100 -tm $1/$1.vk.frag -o $1/$1.frag.vk.spv
	xcrun -sdk macosx metal $1/$1.metal -o $1/$1.air
	xcrun -sdk macosx metallib $1/$1.air -o $1/$1.metallib
	../../../spruce-tools/shader/Debug/spruce-shader $1/$1.gl.vert $1/$1.gl.frag $1/$1.vert.gl.spv $1/$1.frag.gl.spv $1/$1.metallib $1/$1.vert.vk.spv $1/$1.frag.vk.spv $1.spruce-shader
	rm -rf $1/$1.vert.gl.spv
	rm -rf $1/$1.frag.gl.spv
	rm -rf $1/$1.vert.vk.spv
	rm -rf $1/$1.frag.vk.spv
	rm -rf $1/$1.air
	rm -rf $1/$1.metallib
}

createShader default
createShader shadow
createShader post