#pragma once
#include <common.h>
#include <graphics/Texture.h>

namespace spruce {
	class Font {
		public:
			struct charInfo {
				float ax;
				float ay;
				float bw;
				float bh;
				float bl;
				float bt;
				float tx;
			} chars[128];
			string path;
			Texture* texture;

			Font(string& path);
			virtual ~Font();

			void toVRAM();
	};
}
