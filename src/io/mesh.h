#pragma once
#include <common.h>
#include <graphics/Mesh.h>

namespace spruce {
	namespace io {
		Mesh* loadMesh(string& path);
		void writeMesh(string& path, Mesh* mesh);
		uint8* serializeMesh(Mesh* mesh, uint8* data, uint32& offset);
	}
}
