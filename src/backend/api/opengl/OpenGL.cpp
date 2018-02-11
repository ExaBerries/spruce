#include <backend/api/opengl/OpenGL.h>
#include <backend/api/opengl/platform.h>
#include <backend/api/opengl/OpenGLMesh.h>
#include <backend/api/opengl/OpenGLShader.h>
#include <backend/api/opengl/OpenGLShapeRenderer.h>
#include <backend/api/opengl/OpenGLTexture.h>
#include <backend/api/opengl/OpenGLRenderTarget.h>
#include <io/image.h>

namespace spruce {
	OpenGL::OpenGL(Window* window) : RenderAPI(window, vec3f(2, 2, 2)) {
		fontAttributes = nullptr;
		fontShader = nullptr;
		fontVao = 0;
		fontVbo = 0;
		fontVert =
				#include "font.vert"
		;
		fontFrag =
				#include "font.frag"
		;
	}

	OpenGL::~OpenGL() {
		delete fontShader;
		delete[] fontAttributes;
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDeleteBuffers(1, &fontVbo);
		glDeleteVertexArrays(1, &fontVao);
	}

	void OpenGL::init() {
		makeContextCurrent(window);
		swapInterval(window, 1);
		window->setVisible(true);
	}

	void OpenGL::updateStart() {
		glViewport(0, 0, window->width, window->height);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGL::updateEnd() {
		swapBuffers(window);
	}

	Mesh* OpenGL::createMesh(uint16 vertexCount, float* vertices, uint16 indexCount, uint16* indices) {
		return new OpenGLMesh(vertexCount, vertices, indexCount, indices);
	}

	Shader* OpenGL::createShader(uint8* vertData, uint16 vertDataSize, uint8* fragData, uint16 fragDataSize, uint16 attributesCount, VertexAttribute* attributes) {
		return new OpenGLShader(vertData, vertDataSize, fragData, fragDataSize, attributesCount, attributes);
	}

	Shader* OpenGL::createShader(string& vertSource, string& fragSource, uint16 attributesCount, VertexAttribute* attributes) {
		return new OpenGLShader(vertSource, fragSource, attributesCount, attributes);
	}

	ShapeRenderer* OpenGL::createShapeRenderer() {
		return new OpenGLShapeRenderer();
	}

	Texture* OpenGL::createTexture(string& path) {
		uint16 width = 0;
		uint16 height = 0;
		uint16 bitsPerPixel = 0;
		uint8* data = io::loadImage(path, width, height, bitsPerPixel);
		return new OpenGLTexture(Texture::RGBA, data, width, height);
	}

	Texture* OpenGL::createTexture(Texture::PixelFormat format, uint8* data, uint16 width, uint16 height) {
		return new OpenGLTexture(format, data, width, height);
	}

	RenderTarget* OpenGL::createRenderTarget(Texture::PixelFormat format, uint16 width, uint16 height) {
		return new OpenGLRenderTarget(format, width, height);
	}

	void OpenGL::render(Mesh* mesh, Shader* shader) {
		setDepth(true);
		mesh->bind();
		for (int i = 0; i < shader->attributeCount; i++) {
			glEnableVertexAttribArray(shader->getAttributeLocation(shader->attributes[i].name));
		}
		if (mesh->indices > 0) {
			glDrawElements(GL_TRIANGLES, mesh->indexCount, GL_UNSIGNED_SHORT, 0);
		} else {
			glDrawArrays(GL_TRIANGLES, 0, mesh->vertexCount);
		}
		for (int i = 0; i < shader->attributeCount; i++) {
			glDisableVertexAttribArray(shader->getAttributeLocation(shader->attributes[i].name));
		}
		mesh->unbind();
	}

	void OpenGL::renderStart(graphics::RenderPass* renderPass) {
		if (renderPass->target != nullptr) {
			renderPass->target->bind();
			glViewport(0, 0, renderPass->target->width, renderPass->target->height);
		} else {
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
			glViewport(0, 0, window->width, window->height);
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGL::render(string& str, Font& font, vec3f position, quaternion rotation, vec2f size, Camera* camera) {
		if (font.texture == nullptr || font.texture->width == 0 || font.texture->height == 0) {
			return;
		}
		setBlend(true);
		if (fontShader == nullptr) {
			fontAttributes = new VertexAttribute[2];
			fontAttributes[0] = VertexAttribute("position", 3);
			fontAttributes[1] = VertexAttribute("coord", 2);
			string fontVert = OpenGL::fontVert;
			string fontFrag = OpenGL::fontFrag;
			fontShader = createShader(fontVert, fontFrag, 2, fontAttributes);
			fontShader->compile(nullptr);
			fontShader->registerUniform("camera", 1);
			fontShader->registerUniform("tex", 2);
			fontShader->registerUniform("color", 3);
		}
		if (fontVao == 0) {
			glGenVertexArrays(1, &fontVao);
			glBindVertexArray(fontVao);
		}
		if (fontVbo == 0) {
			glBindVertexArray(fontVao);
			glGenBuffers(1, &fontVbo);
			glBindBuffer(GL_ARRAY_BUFFER, fontVbo);
			float stride = sizeof(vec3f) + sizeof(vec2f);
			glEnableVertexAttribArray(fontShader->getAttributeLocation(fontAttributes[0].name));
			glVertexAttribPointer(fontShader->getAttributeLocation(fontAttributes[0].name), 4, GL_FLOAT, GL_FALSE, stride, 0);
			glEnableVertexAttribArray(fontShader->getAttributeLocation(fontAttributes[1].name));
			glVertexAttribPointer(fontShader->getAttributeLocation(fontAttributes[1].name), 4, GL_FLOAT, GL_FALSE, stride, (void*)sizeof(vec3f));
		}
		float x = 0;
		float y = 0;
		struct point {
			vec3f position;
			vec2f coord;
		};
		point coords[6 * str.size()];
		int n = 0;
		for (uint32 i = 0; i < str.size(); i++) {
			char p = str.c_str()[i];
			if (p < 0) {
				continue;
			}
			float x2 = x + font.chars[p].bl * size.x;
			float y2 = -y - font.chars[p].bt * size.y;
			float w = font.chars[p].bw * size.x;
			float h = font.chars[p].bh * size.y;
			x += font.chars[p].ax * size.x;
			y += font.chars[p].ay * size.y;
			if (!w || !h) {
				continue;
			}
			coords[n].position = position + vec3f(x2, -y2, 0) * rotation;
			coords[n].coord = vec2f(font.chars[p].tx, 0);
			n++;
			coords[n].position = position + vec3f(x2 + w, -y2, 0) * rotation;
			coords[n].coord = vec2f(font.chars[p].tx + font.chars[p].bw / font.texture->width, 0);
			n++;
			coords[n].position = position + vec3f(x2, -y2 - h, 0) * rotation;
			coords[n].coord = vec2f(font.chars[p].tx, font.chars[p].bh / font.texture->height);
			n++;
			coords[n].position = position + vec3f(x2 + w, -y2, 0) * rotation;
			coords[n].coord = vec2f(font.chars[p].tx + font.chars[p].bw / font.texture->width, 0);
			n++;
			coords[n].position = position + vec3f(x2, -y2 - h, 0) * rotation;
			coords[n].coord = vec2f(font.chars[p].tx, font.chars[p].bh / font.texture->height);
			n++;
			coords[n].position = position + vec3f(x2 + w, -y2 - h, 0) * rotation;
			coords[n].coord = vec2f(font.chars[p].tx + font.chars[p].bw / font.texture->width, font.chars[p].bh / font.texture->height);
			n++;
		}
		fontShader->enable();
		if (camera != nullptr) {
			fontShader->setUniform("camera", camera->combined);
		} else {
			fontShader->setUniform("camera", mat4f());
		}
		fontShader->setUniform("color", spruce::color(1, 0, 0, 1));
		font.texture->bind();
		fontShader->setUniform("tex", font.texture);
		glBindVertexArray(fontVao);
		glBindBuffer(GL_ARRAY_BUFFER, fontVbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(coords), coords, GL_DYNAMIC_DRAW);
		glDrawArrays(GL_TRIANGLES, 0, n);
		fontShader->disable();
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
		matrix.values[0] = 2 / (right - left);
		matrix.values[1] = 0;
		matrix.values[2] = 0;
		matrix.values[3] = (left + right) / (left - right);
		matrix.values[4] = 0;
		matrix.values[5] = 2 / (top - bottom);
		matrix.values[6] = 0;
		matrix.values[7] = (top + bottom) / (bottom - top);
		matrix.values[8] = 0;
		matrix.values[9] = 0;
		matrix.values[10] = 2 / (near - far);
		matrix.values[11] = near / (near - far);
		matrix.values[12] = 0;
		matrix.values[13] = 0;
		matrix.values[14] = 0;
		matrix.values[15] = 1;
	}
}
