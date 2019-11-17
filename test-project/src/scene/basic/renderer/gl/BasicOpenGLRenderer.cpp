#include <scene/basic/renderer/gl/BasicOpenGLRenderer.h>
#include <scene/basic/Basic.h>
#include <scene/basic/renderer/gl/BasicOpenGLMeshData.h>

namespace sprucetest {
	inline void printGLErr(string id) {
		#define CASE(x) case x: serr(id + " " + #x);break;
		switch (glGetError()) {
			case GL_NO_ERROR: return;
			CASE(GL_INVALID_VALUE);
			CASE(GL_INVALID_ENUM);
			CASE(GL_INVALID_OPERATION);
			default:
				serr("unidentified error");
				break;
		}
	}

	BasicOpenGLRenderer::BasicOpenGLRenderer(Application& app) : OpenGLRenderer<Basic, BasicRendererData>(app) {
		shader = new OpenGLShader();
		shader->compileSource(io::readFileTxt(FileHandle(FileHandle::INTERNAL, "basic/default/default.gl.vert")), io::readFileTxt(FileHandle(FileHandle::INTERNAL, "basic/default/default.gl.frag")));
		shader->createProgram();
		shader->bindAttribLocation(0, "a_position");
	}

	BasicOpenGLRenderer::~BasicOpenGLRenderer() {
		delete shader;
	}

	BasicRendererData BasicOpenGLRenderer::encode(Basic& encodeData) noexcept {
		encodeData.camera->update(this);
		BasicRendererData data;
		data.windowSize = encodeData.windowSize;
		data.cameraTrans = encodeData.camera->combined;
		data.cubeMesh = encodeData.cubeMesh;
		vec3f pos(0, 0, 0);
		quaternion rot(0, 0, 0, 1);
		vec3f scale(1, 1, 1);
		data.worldTrans = mat4f(pos, rot, scale);
		data.color = color(1, 1, 1, 1);
		return data;
	}

	inline void render(BasicMeshData* meshData) {
		glEnableVertexAttribArray(0);
		if (meshData->ibo > 0) {
			glDrawElements(GL_TRIANGLES, meshData->indexCount, GL_UNSIGNED_SHORT, 0);
		} else {
			glDrawArrays(GL_TRIANGLES, 0, meshData->vertexCount);
		}
	}

	void BasicOpenGLRenderer::execute(BasicRendererData& executeData) noexcept {
		glViewport(0, 0, executeData.windowSize.x, executeData.windowSize.y);
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_BLEND);
		glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE);
		glEnable(GL_DEPTH_TEST);
		shader->bind();
		shader->setUniform(glGetUniformLocation(shader->program, "camera"), executeData.cameraTrans);
		shader->setUniform(glGetUniformLocation(shader->program, "worldTrans"), executeData.worldTrans);
		shader->setUniform(glGetUniformLocation(shader->program, "color"), executeData.color);
		Mesh* cubeMesh = executeData.cubeMesh;
		if (cubeMesh != nullptr) {
			((BasicMeshData*)cubeMesh->apiData)->bind();
			render((BasicMeshData*)cubeMesh->apiData);
		}
		context.swapBuffers();
	}

	owner<MeshAPIData> BasicOpenGLRenderer::createMeshAPIData(Mesh& mesh) noexcept {
		return new BasicMeshData(mesh);
	}

	owner<TextureAPIData> BasicOpenGLRenderer::createTextureAPIData(Texture& texture) noexcept {
		return nullptr;
	}
}
