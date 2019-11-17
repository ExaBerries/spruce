#include <scene/info.h>
#include <system/system.h>

void renderInfo(Font* font, string name, float delta) {
	string str;
	std::ostringstream stream;
	//stream << app::apiType << std::endl;
	stream << name << std::endl;
	stream << 1.0 / delta << "fps" << std::endl;
	stream << sys::getSystemInfo() << std::endl;
	//stream << graphics::getGPUVendor() << std::endl;
	//stream << graphics::getAPIVersionMajor << "." << graphics::getAPIVersionMinor << std::endl;
	//stream << graphics::getAPIRendererName << std::endl;
	str = stream.str();
	//graphics::render(str, *font, spruce::color(0, 1, 0, 1), vec3f(-0.98, 0.9, 0), quaternion(0, 0, 0, 1), vec2f(0.05, 0.05 * graphics::width / graphics::height), nullptr);
}
