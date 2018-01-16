#include <io/mesh.h>
#include <graphics/graphics.h>
#include <io/file.h>

namespace spruce {
	namespace io {
		Mesh* loadMesh(const FileHandle& file) {
			uint32 count = 0;
			uint8* data = readFileBin(file, count);
			if (data[0] == 0x0) {
				uint32 offset = 1;
				uint16 vertexCount = 0;
				memcpy(&vertexCount, data + offset, sizeof(uint16));
				offset += sizeof(uint16);
				uint16 indexCount = 0;
				memcpy(&indexCount, data + offset, sizeof(uint16));
				offset += sizeof(uint16);
				float* vertices = new float[vertexCount];
				memcpy(vertices, data + offset, vertexCount * sizeof(float));
				offset += vertexCount * sizeof(float);
				uint16* indices = new uint16[indexCount];
				memcpy(indices, data + offset, indexCount * sizeof(uint16));
				offset += indexCount * sizeof(uint16);
				return graphics::createMesh(vertexCount, vertices, indexCount, indices);
			}
			return nullptr;
		}

		void writeMesh(const FileHandle& file, Mesh* mesh) {
			uint32 size = 1;
			size += sizeof(uint16);
			size += sizeof(uint16);
			size += mesh->vertexCount * sizeof(float);
			size += mesh->indexCount * sizeof(uint16);
			uint8* data = new uint8[size];
			uint32 offset = 1;
			data[0] = 0;
			serializeMesh(mesh, data, offset);
			writeFileBin(file, data, size);
		}

		uint8* serializeMesh(Mesh* mesh, uint8* data, uint32& offset) {
			memcpy(data + offset, &(mesh->vertexCount), sizeof(uint16));
			offset += sizeof(uint16);
			memcpy(data + offset, &(mesh->indexCount), sizeof(uint16));
			offset += sizeof(uint16);
			memcpy(data + offset, mesh->vertices, mesh->vertexCount * sizeof(float));
			offset += mesh->vertexCount * sizeof(float);
			memcpy(data + offset, mesh->indices, mesh->indexCount * sizeof(uint16));
			offset += mesh->indexCount * sizeof(uint16);
			return data;
		}
	}
}
