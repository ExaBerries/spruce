project(
	'spruce-test',
	['c', 'cpp'],
	version: '0.0.9',
	default_options: [
		'buildtype=release',
		'cpp_std=c++17',
		'warning_level=1'
	],
	license: 'MIT'
)

srcs = [
	'src/main.cpp',
	'src/util.cpp',
	'src/SpruceTest.cpp',
	'src/scene/Scene.cpp',
	'src/scene/info.cpp',
	'src/scene/cube/Cube.cpp',
	'src/scene/cube/renderer/CubeRenderData.cpp',
	'src/scene/cube/renderer/CubeOpenGLRenderer.cpp',
	'src/scene/cube/renderer/CubeOpenGLMeshData.cpp',
	'src/scene/cube/renderer/CubeInstanceData.cpp',
	'src/scene/bench/Bench.cpp',
	'src/scene/basic/Basic.cpp',
	'src/scene/basic/renderer/BasicRendererData.cpp',
	'src/scene/basic/renderer/gl/BasicOpenGLRenderer.cpp',
	'src/scene/basic/renderer/gl/BasicOpenGLMeshData.cpp',
	'src/scene/basic/renderer/metal/BasicMetalRenderer.cpp',
	'src/scene/basic/renderer/metal/BasicMetalMeshData.cpp'
]

executable('spruce-test', srcs)
