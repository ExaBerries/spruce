#include <scene/bench/Bench.h>
#include <util.h>

namespace sprucetest {
	Bench::Bench() {
		angle = 0;
	}

	Bench::~Bench() {
	}

	void Bench::load(RendererAbstractor* renderer) {
	}

	void Bench::update(float delta) {
	}

	owner<RendererAbstractor> Bench::getRenderer(SpruceTest& app, app::API api) {
		return nullptr;
	}
}
