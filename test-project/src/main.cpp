#include <spruce.h>
#include <SpruceTest.h>

int main() {
	spruce::SpruceEngine engine([](spruce::SpruceEngine& engine) -> owner<Application> {
		return new sprucetest::SpruceTest(engine);
	});
	engine.run();
	return EXIT_SUCCESS;
}
