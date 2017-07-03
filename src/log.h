#pragma once

namespace spruce {
	extern void log(char& value);
	extern void log(short& value);
	extern void log(int& value);
	extern void log(long& value);
	extern void log(long long& value);
	extern void logGLError();
}
