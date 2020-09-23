#include <scene/cube/Cube.h>
#include <scene/cube/renderer/CubeOpenGLRenderer.h>
#include <util.h>

namespace sprucetest {
	Cube::Cube() {
		cube = createCube(vec3f(1, 1, 1));
		plane = createPlane(vec2f(8, 8));
		screenQuad = createScreenQuad();
		camera = newaown<PerspectiveCamera>(windowSize.x, windowSize.y, 1.25664, 0.1, 10, vec3f(0, 1, 0), vec3f(1, 0, 0));
		angle = 0;
	}

	Cube::~Cube() {
	}

	void Cube::load(RendererAbstractor* renderer) {
		if (cube->apiData != nullptr) {
			cube->freeVRAM();
		}
		if (plane->apiData != nullptr) {
			plane->freeVRAM();
		}
		if (screenQuad->apiData != nullptr) {
			screenQuad->freeVRAM();
		}
		cube->toVRAM(renderer);
		plane->toVRAM(renderer);
		screenQuad->toVRAM(renderer);
	}

	void Cube::update(float delta) {
		if (angle < 2 * M_PI) {
			angle += 0.01;
		} else {
			angle = 0;
		}
		camera->position.set(4 * cos(angle), 0, 4 * sin(angle));
		vec3f x(1, 0, 0);
		vec3f dir = vec3f(0, 0, 0) - camera->position;
		if (dir.x != 4 && dir.x != -4) {
			camera->rotation.set(x, dir);
		} else {
			if (dir.x > 0) {
				camera->rotation.set(0, 0, 0, 1);
			} else {
				camera->rotation.set({0, 1, 0}, M_PI);
			}
		}
		camera->viewportWidth = windowSize.x;
		camera->viewportHeight = windowSize.y;
	}

	owner<RendererAbstractor> Cube::getRenderer(SpruceTest& app, app::API api) {
		if (api == app::OPENGL) {
			return new CubeOpenGLRenderer(app);
		} else {
			serr("no renderer for api ", api);
			return nullptr;
		}
	}
}
