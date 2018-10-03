#include <backend/api/opengl/OpenGL.h>
#include <backend/api/opengl/platform.h>
#include <backend/api/opengl/OpenGLMesh.h>
#include <backend/api/opengl/OpenGLShader.h>
#include <backend/api/opengl/OpenGLTexture.h>
#include <backend/api/opengl/OpenGLRenderTarget.h>
#include <io/image.h>
#include <graphics/graphics.h>

namespace spruce {
	OpenGL::OpenGL(Window* window) : RenderAPI(window, vec3f(2, 2, 2)) {
	}

	OpenGL::~OpenGL() {
	}

	void OpenGL::createContext() {
	}

	void OpenGL::surfaceCreated() {
		window->setVisible(true);
		string fontVert =
			#include "font.vert"
		;
		string fontFrag =
			#include "font.frag"
		;
		string shapeVert =
			#include "shape.vert"
		;
		string shapeFrag =
			#include "shape.frag"
		;
		buffer<VertexAttribute> fontAttributes(2);
		fontAttributes[0] = VertexAttribute("position", 3);
		fontAttributes[1] = VertexAttribute("texCoord", 2);
		Shader* fontShader = createShader(fontVert, fontFrag, fontAttributes);
		fontShader->compile(nullptr);
		fontShader->registerUniform("camera", Shader::VERTEX, 1);
		fontShader->registerUniform("tex", Shader::FRAGMENT, 2);
		fontShader->registerUniform("color", Shader::FRAGMENT, 3);
		fontBatcher = new FontBatcher(fontAttributes, fontShader);
		buffer<VertexAttribute> shapeAttributes(2);
		shapeAttributes[0] = VertexAttribute("a_pos", 3);
		shapeAttributes[1] = VertexAttribute("a_color", 4);
		Shader* shapeShader = createShader(shapeVert, shapeFrag, shapeAttributes);
		shapeShader->compile(nullptr);
		shapeShader->registerUniform("camera", Shader::VERTEX, 1);
		shapeBatcher = new ShapeBatcher(shapeAttributes, shapeShader);
	}

	void OpenGL::renderStart() {
		glViewport(0, 0, window->width, window->height);
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGL::renderEnd() {
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

	void OpenGL::render(buffer<float> vertices, buffer<uint16> indices, Shader* shader, graphics::Primitive primitive) {
		if (vertices.size == 0) {
			serr("no vertices to render");
			return;
		}
		GLuint vao = 0;
		GLuint vbo = 0;
		GLuint ibo = 0;
		if (vao == 0) {
			glGenVertexArrays(1, &vao);
		}
		glBindVertexArray(vao);
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, vertices.size * sizeof(float), vertices.data, GL_DYNAMIC_DRAW);
		uint16 stride = 0;
		for (int i = 0; i < shader->attributes.size; i++) {
			stride += shader->attributes[i].size;
		}
		stride *= sizeof(float);
		uint8* offset = 0;
		for (int j = 0; j < shader->attributes.size; j++) {
			glVertexAttribPointer(shader->getAttributeLocation(shader->attributes[j].name), shader->attributes[j].size, GL_FLOAT, GL_FALSE, stride, offset);
			offset += shader->attributes[j].size * sizeof(float);
		}
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		if (indices.size > 0) {
			glGenBuffers(1, &ibo);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size * sizeof(uint16), indices.data, GL_DYNAMIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

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
		glBindVertexArray(vao);
		if (ibo > 0) {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		}
		for (int i = 0; i < shader->attributes.size; i++) {
			glEnableVertexAttribArray(shader->getAttributeLocation(shader->attributes[i].name));
		}
		if (indices.size > 0) {
			glDrawElements(glPrimitive, indices.size, GL_UNSIGNED_SHORT, 0);
		} else {
			glDrawArrays(glPrimitive, 0, vertices.size);
		}
		for (int i = 0; i < shader->attributes.size; i++) {
			glDisableVertexAttribArray(shader->getAttributeLocation(shader->attributes[i].name));
		}

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDeleteBuffers(1, &vbo);
		if (ibo > 0) {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			glDeleteBuffers(1, &ibo);
		}
		glDeleteVertexArrays(1, &vao);
	}

	void OpenGL::changeTarget(RenderTarget* target) {
		if (((OpenGLRenderTarget*)target)->texture != nullptr) {
			bind(((OpenGLRenderTarget*)target)->texture);
		}
		glBindFramebuffer(GL_FRAMEBUFFER, ((OpenGLRenderTarget*)target)->framebuffer);
		glViewport(0, 0, target->width, target->height);
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
		glEnable(GL_BLEND);
		glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE);
		glEnable(GL_DEPTH_TEST);
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

	void OpenGL::setUniform(Shader* shader, string name, Texture* texture) {
		bind((Texture*)texture);
		glUniform1i(shader->uniformLocations[name].index, ((OpenGLTexture*)texture)->unit);
	}

	void OpenGL::setUniform(Shader* shader, string name, graphics::RenderPass* renderPass) {
		bind(((const OpenGLRenderTarget*)renderPass->target)->texture);
		glUniform1i(shader->uniformLocations[name].index, ((OpenGLRenderTarget*)renderPass->target)->texture->unit);
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
