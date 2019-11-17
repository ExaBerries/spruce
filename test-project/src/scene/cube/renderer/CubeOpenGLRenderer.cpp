#include <scene/cube/renderer/CubeOpenGLRenderer.h>
#include <scene/cube/renderer/CubeOpenGLMeshData.h>
#include <scene/cube/Cube.h>

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

	CubeOpenGLRenderer::CubeOpenGLRenderer(Application& app) : OpenGLRenderer<Cube, CubeRenderData>(app) {
		shader = new OpenGLShader();
		string vertString = io::readFileTxt(FileHandle(FileHandle::INTERNAL, "cube/default/default.gl.vert"));
		string fragString = io::readFileTxt(FileHandle(FileHandle::INTERNAL, "cube/default/default.gl.frag"));
		shader->compileSource(vertString, fragString);
		shader->createProgram();
		shader->bindAttribLocation(0, "position");

		postShader = new OpenGLShader();
		string postVertString = io::readFileTxt(FileHandle(FileHandle::INTERNAL, "cube/post/post.gl.vert"));
		string postFragString = io::readFileTxt(FileHandle(FileHandle::INTERNAL, "cube/post/post.gl.frag"));
		postShader->compileSource(postVertString, postFragString);
		postShader->createProgram();
		postShader->bindAttribLocation(0, "position");
		postShader->bindAttribLocation(1, "a_uv");

		uint16 width = 1280;
		uint16 height = 720;
		mainTarget = new OpenGLColorRenderTarget(width, height, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE);
		bloomTarget = new OpenGLColorRenderTarget(width, height, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE);
		main = new OpenGLFramebuffer();
		main->bind();
		main->createDepthRenderBuffer(width, height);
		buffer<GLenum> attachments(2);
		attachments[0] = GL_COLOR_ATTACHMENT0;
		attachments[1] = GL_COLOR_ATTACHMENT1;
		mainTarget->attachToBoundFramebuffer(attachments[0]);
		bloomTarget->attachToBoundFramebuffer(attachments[1]);
		main->setDrawBuffers(attachments);
		attachments.free();
		if (!main->complete()) {
			serr("incomplete main fbo");
		}

		printGLErr("create end");
	}

	CubeOpenGLRenderer::~CubeOpenGLRenderer() {
		delete shader;
		delete postShader;
		delete mainTarget;
		delete bloomTarget;
		delete main;
	}

	CubeRenderData CubeOpenGLRenderer::encode(Cube& encodeData) noexcept {
		encodeData.camera->update(this);
		CubeRenderData data;
		data.viewport = vec2i(encodeData.windowSize.x, encodeData.windowSize.y);
		data.cube = encodeData.cube;
		data.plane = encodeData.plane;
		data.cameraTrans = encodeData.camera->combined;
		data.sunDir = vec3f(-1, -1, 0);
		{
			CubeInstanceData a;
			vec3f apos(0, 0, 0);
			quaternion arot(0, 0, 0, 1);
			vec3f ascale(1, 1, 1);
			a.worldTrans = mat4f(apos, arot, ascale);
			a.color = color(1, 0.4, 0, 1);

			CubeInstanceData b;
			vec3f bpos(0, 1, 0);
			quaternion brot(0, 0, 0, 1);
			vec3f bscale(1, 1, 1);
			b.worldTrans = mat4f(bpos, brot, bscale);
			b.color = color(1, 1, 0, 1);

			CubeInstanceData c;
			vec3f cpos(1, 0, 0);
			quaternion crot(0, 0, 0, 1);
			vec3f cscale(1, 1, 1);
			c.worldTrans = mat4f(cpos, crot, cscale);
			c.color = color(1, 0, 1, 1);

			CubeInstanceData d;
			vec3f dpos(2, 0, 2);
			quaternion drot(0, 0, 0, 1);
			vec3f dscale(1, 1, 1);
			d.worldTrans = mat4f(dpos, drot, dscale);
			d.color = color(0, 1, 1, 1);

			data.cubeInstances.push_back(a);
			data.cubeInstances.push_back(b);
			data.cubeInstances.push_back(c);
			data.cubeInstances.push_back(d);
		}
		vec3f ppos(0, -0.5, 0);
		quaternion prot(0, 0, 0, 1);
		vec3f pscale(1, 1, 1);
		data.planeTrans = mat4f(ppos, prot, pscale);
		data.planeCol = color(0, 1, 0, 1);
		data.screenQuad = encodeData.screenQuad;
		return data;
	}

	inline void render(CubeOpenGLMeshData* meshData, OpenGLShader* shader, string* vertexAttribArrays, uint8 vaaCount) {
		for (uint8 i = 0; i < vaaCount; i++) {
			glEnableVertexAttribArray(glGetAttribLocation(shader->program, vertexAttribArrays[i].c_str()));
		}
		if (meshData->ibo > 0) {
			glDrawElements(GL_TRIANGLES, meshData->indexCount, GL_UNSIGNED_SHORT, 0);
		} else {
			glDrawArrays(GL_TRIANGLES, 0, meshData->vertexCount);
		}
		for (uint8 i = 0; i < vaaCount; i++) {
			glDisableVertexAttribArray(glGetAttribLocation(shader->program, vertexAttribArrays[i].c_str()));
		}
	}

	void CubeOpenGLRenderer::execute(CubeRenderData& executeData) noexcept {
		mainTarget->bind(GL_TEXTURE1);
		bloomTarget->bind(GL_TEXTURE2);
		main->bind();
		glViewport(0, 0, 1280, 720);
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_BLEND);
		glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE);
		glEnable(GL_DEPTH_TEST);

		string mainAttribs[1] = {"position"};
		shader->bind();
		shader->setUniform(glGetUniformLocation(shader->program, "camera"), executeData.cameraTrans);
		for (CubeInstanceData& data : executeData.cubeInstances) {
			shader->setUniform(glGetUniformLocation(shader->program, "worldTrans"), data.worldTrans);
			shader->setUniform(glGetUniformLocation(shader->program, "color"), data.color);
			Mesh* cubeMesh = executeData.cube;
			if (cubeMesh != nullptr) {
				((CubeOpenGLMeshData*)cubeMesh->apiData)->bind();
				if (!((CubeOpenGLMeshData*)cubeMesh->apiData)->attribPointers) {
					glBindBuffer(GL_ARRAY_BUFFER, ((CubeOpenGLMeshData*)cubeMesh->apiData)->vbo);
					uint16 posAttribArr = glGetAttribLocation(shader->program, "position");
					glVertexAttribPointer(posAttribArr, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
					glBindBuffer(GL_ARRAY_BUFFER, 0);
					((CubeOpenGLMeshData*)cubeMesh->apiData)->attribPointers = true;
				}
				render((CubeOpenGLMeshData*)cubeMesh->apiData, shader, mainAttribs, 1);
			}
		}
		shader->setUniform(glGetUniformLocation(shader->program, "worldTrans"), executeData.planeTrans);
		shader->setUniform(glGetUniformLocation(shader->program, "color"), executeData.planeCol);
		Mesh* planeMesh = executeData.plane;
		((CubeOpenGLMeshData*)planeMesh->apiData)->bind();
		if (!((CubeOpenGLMeshData*)planeMesh->apiData)->attribPointers) {
			glBindBuffer(GL_ARRAY_BUFFER, ((CubeOpenGLMeshData*)planeMesh->apiData)->vbo);
			uint16 posAttribArr = glGetAttribLocation(shader->program, "position");
			glVertexAttribPointer(posAttribArr, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			((CubeOpenGLMeshData*)planeMesh->apiData)->attribPointers = true;
		}
		render((CubeOpenGLMeshData*)planeMesh->apiData, shader, mainAttribs, 1);

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		glViewport(0, 0, executeData.viewport.x, executeData.viewport.y);
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glDisable(GL_BLEND);
		glEnable(GL_DEPTH_TEST);
		postShader->bind();
		postShader->setUniform(glGetUniformLocation(postShader->program, "mainPass"), 1);
		postShader->setUniform(glGetUniformLocation(postShader->program, "bloomPass"), 2);
		postShader->setUniform(glGetUniformLocation(postShader->program, "res"), vec2f(1280, 720));
		string postAttribs[2] = {"position", "a_uv"};

		Mesh* screenQuad = executeData.screenQuad;
		((CubeOpenGLMeshData*)screenQuad->apiData)->bind();
		if (!((CubeOpenGLMeshData*)screenQuad->apiData)->attribPointers) {
			glBindBuffer(GL_ARRAY_BUFFER, ((CubeOpenGLMeshData*)screenQuad->apiData)->vbo);
			uint16 posAttribArr = glGetAttribLocation(postShader->program, "position");
			uint16 uvAttribArr = glGetAttribLocation(postShader->program, "a_uv");
			glVertexAttribPointer(posAttribArr, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);
			glVertexAttribPointer(uvAttribArr, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*) (3 * sizeof(float)));
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			((CubeOpenGLMeshData*)screenQuad->apiData)->attribPointers = true;
		}
		render((CubeOpenGLMeshData*)screenQuad->apiData, postShader, postAttribs, 2);

		printGLErr("execute end");

		context.swapBuffers();
	}

	owner<MeshAPIData> CubeOpenGLRenderer::createMeshAPIData(Mesh& mesh) noexcept {
		return new CubeOpenGLMeshData(mesh);
	}

	owner<TextureAPIData> CubeOpenGLRenderer::createTextureAPIData(Texture& texture) noexcept {
		return nullptr;
	}
}
