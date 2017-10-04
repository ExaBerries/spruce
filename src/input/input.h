#pragma once
#include <common.h>
#include <math/vec2f.h>
#include <input/InputSource.h>
#include <input/BasicInputSource.h>

namespace spruce {
	namespace input {
		enum Key {
			A,
			B,
			C,
			D,
			E,
			F,
			G,
			H,
			I,
			J,
			K,
			L,
			M,
			N,
			O,
			P,
			Q,
			R,
			S,
			T,
			U,
			V,
			W,
			X,
			Y,
			Z,
			ZERO,
			ONE,
			TWO,
			THREE,
			FOUR,
			FIVE,
			SIX,
			SEVEN,
			EIGHT,
			NINE,
			ENTER,
			ESCAPE,
			DELETE,
			TAB,
			SPACE,
			SHIFT_LEFT,
			SHIFT_RIGHT,
			CONTROL_LEFT,
			CONTROL_RIGHT,
			F1,
			F2,
			F3,
			F4,
			F5,
			F6,
			F7,
			F8,
			F9,
			F10,
			F11,
			F12
		};
		enum MouseButton {
			LEFT,
			CENTER,
			RIGHT
		};
		enum CursorMode {
			NORMAL,
			HIDDEN,
			DISABLED
		};

		void setCursorMode(CursorMode mode);

		bool keyPressed(Key key);
		bool mouseButtonPressed(MouseButton button);
		vec2f mousePos();

		uint16 codeFor(Key key);
		uint16 codeFor(MouseButton button);
	}
}
