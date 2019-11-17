#include <SpruceTest.h>
#include <scene/basic/Basic.h>
#include <scene/cube/Cube.h>
#include <scene/bench/Bench.h>

namespace sprucetest {
	SpruceTest::SpruceTest(SpruceEngine& engine) : Application(engine) {
		setFramePipeline(new SimplePipeline());
		setRenderAPI(app::OPENGL);
		input::addProcessor(this);
		swapAPI = false;
		swapScene = false;
		font = nullptr;
		scene = new Basic();
		setRenderer(scene->getRenderer(*this, engine.apiType));
		scene->load(getRenderer());
	}

	SpruceTest::~SpruceTest() {
		delete (Scene*)scene;
	}

	void swapAPIto(SpruceTest& app, app::API newAPI, Scene* scene) {
		app.setRenderAPI(newAPI);
		app.setRenderer(scene->getRenderer(app, newAPI));
		scene->load(app.getRenderer());
	}

	void swapToScene(SpruceTest& app, SpruceTest::SCENE& sceneType, owner<Scene>& scene) {
		delete (Scene*)scene;
		switch (sceneType) {
			case SpruceTest::BASIC:
				scene = new Cube();
				sceneType = SpruceTest::CUBE;
				break;
			case SpruceTest::CUBE:
				scene = new Bench();
				sceneType = SpruceTest::BENCH;
				break;
			case SpruceTest::BENCH:
				scene = new Basic();
				sceneType = SpruceTest::BASIC;
				break;
			default:
				scene = new Cube();
				sceneType = SpruceTest::CUBE;
				break;
		}
		app.setRenderer(scene->getRenderer(app, app.engine.apiType));
		scene->load(app.getRenderer());
		slog("swapped scene to ", sceneType);
	}

	void SpruceTest::update(float delta) noexcept {
		scene->windowSize = vec2i(getWindow()->width, getWindow()->height);
		if (swapAPI) {
			const buffer<app::API> supportedAPIs = getSupportedAPIs();
			app::API newapi = app::OPENGL;
			for (uint16 i = 0; i < supportedAPIs.size; i++) {
				if (supportedAPIs[i] == engine.apiType) {
					newapi = supportedAPIs[(i + 1) % supportedAPIs.size];
					break;
				}
			}
			Task<void(SpruceTest&, app::API, Scene*)> task = createTask<SpruceTest&, app::API, Scene*>(std::function<void(SpruceTest&, app::API, Scene*)>(swapAPIto), task::FRAME, false, *this, newapi, scene);
			swapAPI = false;
		}
		if (swapScene) {
			Task<void(SpruceTest&, SpruceTest::SCENE&, owner<Scene>&)> task = createTask<SpruceTest&, SpruceTest::SCENE&, owner<Scene>&>(std::function<void(SpruceTest&, SpruceTest::SCENE&, owner<Scene>&)>(swapToScene), task::FRAME, false, *this, sceneType, scene);
			swapScene = false;
		}
		scene->update(delta);
	}

	void* SpruceTest::getRenderEncodeData() noexcept {
		return scene;
	}

	void SpruceTest::keyDown(uint16 code) noexcept {
		if (code == input::codeFor(input::BACKSLASH)) {
			swapAPI = true;
		}
		if (code == input::codeFor(input::EQUAL)) {
			swapScene = true;
		}
		if (code == input::codeFor(input::MINUS)) {
			//graphics::vsync = !graphics::vsync;
		}
	}

	void SpruceTest::keyUp(uint16 code) noexcept {
	}

	void SpruceTest::mouseDown(input::MouseButton button) noexcept {
	}

	void SpruceTest::mouseUp(input::MouseButton button) noexcept {
	}

	void SpruceTest::mouseMove(vec2f newPos)  noexcept {
	}
}
