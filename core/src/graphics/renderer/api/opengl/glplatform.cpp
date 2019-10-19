#include <graphics/renderer/api/opengl/glplatform.h>

#ifdef __APPLE__
	void glSpecializeShader([[maybe_unused]] GLuint shader, [[maybe_unused]] const GLchar* entryPoint, [[maybe_unused]] GLuint c, [[maybe_unused]] void* d, [[maybe_unused]] void* e) {
	}
#endif
