#pragma once
#include <common.h>
#include <graphics/Mesh.h>
#include <io/FileHandle.h>

namespace spruce {
	namespace io {
		Mesh* loadMesh(const FileHandle& path);
		void writeMesh(const FileHandle& path, Mesh* mesh);
		uint8* serializeMesh(Mesh* mesh, uint8* data, uint32& offset);
	}
}
