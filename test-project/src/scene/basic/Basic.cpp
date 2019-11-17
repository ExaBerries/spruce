#include <scene/basic/Basic.h>
#include <scene/basic/renderer/gl/BasicOpenGLRenderer.h>
#include <scene/basic/renderer/metal/BasicMetalRenderer.h>
#include <util.h>
#include <scene/info.h>

namespace sprucetest {
	Basic::Basic() {
		vec3f dir(1, 0, 0);
		vec3f up(0, 1, 0);
		camera = newaown<PerspectiveCamera>(1280, 720, 1.3, 1, 10, up, dir);
		camera->position = {-2, 0, 0};
		cubeMesh = createCube(vec3f(1, 1, 1));
		angle = 0;
	}

	Basic::~Basic() {
	}

	void Basic::load(RendererAbstractor* renderer) {
		if (cubeMesh->apiData != nullptr) {
			cubeMesh->freeVRAM();
		}
		cubeMesh->toVRAM(renderer);
	}

	void Basic::update(float delta) {
		if (angle < 2 * M_PI) {
			angle += 0.01;
		} else {
			angle = 0;
		}
		camera->position.set(4 * cos(angle), 1, 4 * sin(angle));
		vec3f x(1, 0, 0);
		vec3f dir = vec3f(0, 0, 0) - camera->position;
		camera->rotation.set(x, dir);
	}

	owner<RendererAbstractor> Basic::getRenderer(SpruceTest& app, app::API api) {
		slog(api);
		if (api == app::OPENGL) {
			return new BasicOpenGLRenderer(app);
		} else if (api == app::METAL) {
			return new BasicMetalRenderer(app);
		} else {
			serr("no renderer for api ", api);
			return nullptr;
		}
	}
}
