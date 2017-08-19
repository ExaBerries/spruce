#pragma once
#include <common.h>
#include <input/InputMap.h>

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
			CONTROL_RIGHT
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

		uint16 codeFor(Key key);
		uint16 codeFor(MouseButton button);
	}
}
