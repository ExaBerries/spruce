#include <backend/api/opengl/OpenGL.h>
#include <backend/api/opengl/platform.h>
#include <backend/api/opengl/OpenGLMesh.h>
#include <backend/api/opengl/OpenGLShader.h>
#include <backend/api/opengl/OpenGLTexture.h>
#include <backend/api/opengl/OpenGLRenderTarget.h>
#include <io/image.h>

namespace spruce {
	OpenGL::OpenGL(Window* window) : RenderAPI(window, vec3f(2, 2, 2)) {
		fontVert =
			#include "font.vert"
		;
		fontFrag =
			#include "font.frag"
		;
		shapeVert =
			#include "shape.vert"
		;
		shapeFrag =
			#include "shape.frag"
		;
	}

	OpenGL::~OpenGL() {
	}

	void OpenGL::init() {
		makeContextCurrent(window);
		swapInterval(window, 1);
		window->setVisible(true);
		fontAttributes = buffer<VertexAttribute>(2);
		fontAttributes[0] = VertexAttribute("position", 3);
		fontAttributes[1] = VertexAttribute("texCoord", 2);
		fontShader = createShader(fontVert, fontFrag, fontAttributes);
		fontShader->compile(nullptr);
		fontShader->registerUniform("camera", Shader::VERTEX, 1);
		fontShader->registerUniform("tex", Shader::FRAGMENT, 2);
		fontShader->registerUniform("color", Shader::FRAGMENT, 3);
		fontMesh = createMesh(nullptr, nullptr);
		shapeAttributes = buffer<VertexAttribute>(2);
		shapeAttributes[0] = VertexAttribute("a_pos", 3);
		shapeAttributes[1] = VertexAttribute("a_color", 4);
		shapeShader = createShader(shapeVert, shapeFrag, shapeAttributes);
		shapeShader->compile(nullptr);
		shapeShader->registerUniform("camera", Shader::VERTEX, 1);
		shapeMesh = createMesh(nullptr, nullptr);
	}

	void OpenGL::renderStart() {
		glViewport(0, 0, window->width, window->height);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGL::renderEnd() {
		swapBuffers(window);
	}

	string OpenGL::getError() {
		return std::to_string(glGetError());
	}

	Mesh* OpenGL::createMesh(buffer<float> vertices, buffer<uint16> indices) {
		return new OpenGLMesh(vertices, indices);
	}

	Shader* OpenGL::createShader(buffer<uint8> vertData, buffer<uint8> fragData, buffer<VertexAttribute> attributes) {
		return new OpenGLShader(vertData, fragData, attributes);
	}

	Shader* OpenGL::createShader(string& vertSource, string& fragSource, buffer<VertexAttribute> attributes) {
		return new OpenGLShader(vertSource, fragSource, attributes);
	}

	Texture* OpenGL::createTexture(const FileHandle& path) {
		uint16 width = 0;
		uint16 height = 0;
		uint16 bitsPerPixel = 0;
		buffer<uint8> data = io::loadImage(path, width, height, bitsPerPixel);
		return new OpenGLTexture(Texture::RGBA, data, width, height);
	}

	Texture* OpenGL::createTexture(Texture::PixelFormat format, buffer<uint8> data, uint16 width, uint16 height) {
		return new OpenGLTexture(format, data, width, height);
	}

	RenderTarget* OpenGL::createRenderTarget(Texture::PixelFormat format, uint16 width, uint16 height) {
		return new OpenGLRenderTarget(format, width, height);
	}

	void OpenGL::render(Mesh* mesh, Shader* shader, graphics::Primitive primitive) {
		GLuint glPrimitive;
		switch (primitive) {
			case graphics::TRIANGLE:
				glPrimitive = GL_TRIANGLES;
				break;
			case graphics::TRIANGLE_STRIP:
				glPrimitive = GL_TRIANGLE_STRIP;
				break;
			case graphics::LINE:
				glPrimitive = GL_LINES;
				break;
			case graphics::LINE_STRIP:
				glPrimitive = GL_LINE_STRIP;
				break;
			default:
				glPrimitive = GL_TRIANGLES;
				break;
		}
		setDepth(true);
		bind(mesh);
		for (int i = 0; i < shader->attributes.size; i++) {
			glEnableVertexAttribArray(shader->getAttributeLocation(shader->attributes[i].name));
		}
		if (mesh->indices.size > 0) {
			glDrawElements(glPrimitive, mesh->indices.size, GL_UNSIGNED_SHORT, 0);
		} else {
			glDrawArrays(glPrimitive, 0, mesh->vertices.size);
		}
		for (int i = 0; i < shader->attributes.size; i++) {
			glDisableVertexAttribArray(shader->getAttributeLocation(shader->attributes[i].name));
		}
	}

	void OpenGL::renderStart(graphics::RenderPass* renderPass) {
		if (renderPass->target != nullptr) {
			bind(((OpenGLRenderTarget*)renderPass->target)->texture);
			glBindFramebuffer(GL_FRAMEBUFFER, ((OpenGLRenderTarget*)renderPass->target)->framebuffer);
			glViewport(0, 0, renderPass->target->width, renderPass->target->height);
		} else {
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
			glViewport(0, 0, window->width, window->height);
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGL::bind(Mesh* mesh) {
		glBindVertexArray(((OpenGLMesh*)mesh)->vao);
		if (((OpenGLMesh*)mesh)->ibo > 0) {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ((OpenGLMesh*)mesh)->ibo);
		}
	}

	void OpenGL::bind(Texture* texture) {
		if (!((OpenGLTexture*) texture)->unit) {
			((OpenGLTexture*) texture)->unit = ((OpenGLTexture*) texture)->getFreeUnit();
			((OpenGLTexture*) texture)->units[((OpenGLTexture*) texture)->unit] = true;
		}
		glActiveTexture(GL_TEXTURE0 + ((OpenGLTexture*) texture)->unit);
		glBindTexture(GL_TEXTURE_2D, ((OpenGLTexture*) texture)->texture);
	}

	void OpenGL::unbind(Texture* texture) {
		if (((OpenGLTexture*) texture)->units != nullptr) {
			((OpenGLTexture*) texture)->units[((OpenGLTexture*) texture)->unit] = false;
			((OpenGLTexture*) texture)->unit = 0;
		}
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void OpenGL::bind(Shader* shader) {
		glUseProgram(((OpenGLShader*)shader)->program);
	}

	void OpenGL::setUniform(Shader* shader, string name, const int32& value) {
		glUniform1i(shader->uniformLocations[name].index, value);
	}

	void OpenGL::setUniform(Shader* shader, string name, const vec2i& vector) {
		glUniform2i(shader->uniformLocations[name].index, vector.x, vector.y);
	}

	void OpenGL::setUniform(Shader* shader, string name, const float& value) {
		glUniform1f(shader->uniformLocations[name].index, value);
	}

	void OpenGL::setUniform(Shader* shader, string name, const vec2f& vector) {
		glUniform2f(shader->uniformLocations[name].index, vector.x, vector.y);
	}

	void OpenGL::setUniform(Shader* shader, string name, const vec3f& vector) {
		glUniform3f(shader->uniformLocations[name].index, vector.x, vector.y, vector.z);
	}

	void OpenGL::setUniform(Shader* shader, string name, const mat4f& matrix) {
		glUniformMatrix4fv(shader->uniformLocations[name].index, 1, GL_TRUE, matrix.values);
	}

	void OpenGL::setUniform(Shader* shader, string name, const quaternion& quaternion) {
		glUniform4f(shader->uniformLocations[name].index, quaternion.x, quaternion.y, quaternion.z, quaternion.w);
	}

	void OpenGL::setUniform(Shader* shader, string name, const color& color) {
		glUniform4f(shader->uniformLocations[name].index, color.r, color.g, color.b, color.a);
	}

	void OpenGL::setUniform(Shader* shader, string name, const Texture* texture) {
		bind((Texture*)texture);
		glUniform1i(shader->uniformLocations[name].index, ((OpenGLTexture*)texture)->unit);
	}

	void OpenGL::setUniform(Shader* shader, string name, const graphics::RenderPass* renderPass) {
		bind(((OpenGLRenderTarget*)renderPass->target)->texture);
		glUniform1i(shader->uniformLocations[name].index, ((OpenGLRenderTarget*)renderPass->target)->texture->unit);
	}

	void OpenGL::setBlend(bool value) {
		if (value) {
			glEnable(GL_BLEND);
			glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE);
		} else {
			glDisable(GL_BLEND);
		}
	}

	void OpenGL::setDepth(bool value) {
		if (value) {
			glEnable(GL_DEPTH_TEST);
		} else {
			glDisable(GL_DEPTH_TEST);
		}
	}

	string OpenGL::getGPUVendor() {
		return string(reinterpret_cast<const char*>(glGetString(GL_VENDOR)));
	}

	uint16 OpenGL::getAPIVersionMajor() {
		int32 major = 0;
		glGetIntegerv(GL_MAJOR_VERSION, &major);
		return major;
	}

	uint16 OpenGL::getAPIVersionMinor() {
		int32 minor = 0;
		glGetIntegerv(GL_MINOR_VERSION, &minor);
		return minor;
	}

	string OpenGL::getAPIRendererName() {
		return string(reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
	}

	void OpenGL::setPerspective(mat4f& matrix, float& near, float& far, float& fov, float& aspectRatio) {
		float size = 1.0 / tan(fov / 2.0);
		matrix.values[0] = size / aspectRatio;
		matrix.values[1] = 0.0;
		matrix.values[2] = 0.0;
		matrix.values[3] = 0.0;
		matrix.values[4] = 0.0;
		matrix.values[5] = size;
		matrix.values[6] = 0.0;
		matrix.values[7] = 0.0;
		matrix.values[8] = 0.0;
		matrix.values[9] = 0.0;
		matrix.values[10] = (far + near) / (near - far);
		matrix.values[11] = (2.0 * far * near) / (near - far);
		matrix.values[12] = 0.0;
		matrix.values[13] = 0.0;
		matrix.values[14] = -1.0;
		matrix.values[15] = 0.0;
	}

	void OpenGL::setOrthographic(mat4f& matrix, float left, float right, float top, float bottom, float near, float far) {
		matrix.values[0] = 2.0 / (right - left);
		matrix.values[1] = 0.0;
		matrix.values[2] = 0.0;
		matrix.values[3] = (left + right) / (left - right);
		matrix.values[4] = 0.0;
		matrix.values[5] = 2.0 / (top - bottom);
		matrix.values[6] = 0.0;
		matrix.values[7] = (top + bottom) / (bottom - top);
		matrix.values[8] = 0.0;
		matrix.values[9] = 0.0;
		matrix.values[10] = 2.0 / (near - far);
		matrix.values[11] = near / (near - far);
		matrix.values[12] = 0.0;
		matrix.values[13] = 0.0;
		matrix.values[14] = 0.0;
		matrix.values[15] = 1.0;
	}
}
