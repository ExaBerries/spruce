#pragma once
#include <common.h>
#include <graphics/Mesh.h>
#include <io/FileHandle.h>

namespace spruce {
	namespace io {
		[[nodiscard]] owner<Mesh> loadMesh(const FileHandle& file);
		void writeMesh(const FileHandle& file, Mesh* mesh);
		void serializeMesh(Mesh* mesh, buffer<uint8>& data, uint32& offset);
	}
}
