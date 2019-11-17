function createShader {
	#glslangValidator -G $1/$1.gl.vert -o $1/$1.vert.gl.spv
	#glslangValidator -G $1/$1.gl.frag -o $1/$1.frag.gl.spv
	glslangValidator -V100 -tm $1/$1.vk.vert -o $1/$1.vert.vk.spv
	glslangValidator -V100 -tm $1/$1.vk.frag -o $1/$1.frag.vk.spv
	xcrun -sdk macosx metal $1/$1.metal -o $1/$1.air
	xcrun -sdk macosx metallib $1/$1.air -o $1/$1.metallib
	rm -rf $1/$1.air
}

createShader default
