#include <io/mesh.h>
#include <io/file.h>

namespace spruce {
	namespace io {
		[[nodiscard]] owner<Mesh> loadMesh(const FileHandle& file) {
			buffer<uint8> data = readFileBin(file);
			if (data == nullptr) {
				return nullptr;
			}
			if (data[0] == 0x0) {
				uint8* ptr = data + 1;
				uint16 vertexCount = 0;
				memcpy(&vertexCount, ptr, sizeof(uint16));
				ptr += sizeof(uint16);
				uint16 indexCount = 0;
				memcpy(&indexCount, ptr, sizeof(uint16));
				ptr += sizeof(uint16);
				buffer<float> vertices(vertexCount);
				memcpy(vertices.data, ptr, vertexCount * sizeof(float));
				ptr += vertexCount * sizeof(float);
				buffer<uint16> indices(indexCount);
				memcpy(indices.data, ptr, indexCount * sizeof(uint16));
				return new Mesh(vertices, indices);
			} else if (data[0] == 0x1) {
				uint8* ptr = data + 1;
				uint64 vertexCount = 0;
				memcpy(&vertexCount, ptr, sizeof(uint64));
				ptr += sizeof(uint64);
				uint64 indexCount = 0;
				memcpy(&indexCount, ptr, sizeof(uint64));
				ptr += sizeof(uint64);
				buffer<float> vertices(vertexCount);
				memcpy(vertices.data, ptr, vertexCount * sizeof(float));
				ptr += vertexCount * sizeof(float);
				buffer<uint16> indices(indexCount);
				memcpy(indices.data, ptr, indexCount * sizeof(uint16));
				return new Mesh(vertices, indices);
			}
			return nullptr;
		}

		void writeMesh(const FileHandle& file, Mesh* mesh) {
			uint64 size = 1;
			size += sizeof(uint16);
			size += sizeof(uint16);
			size += mesh->vertices.size * sizeof(float);
			size += mesh->indices.size * sizeof(uint16);
			buffer<uint8> data(size);
			uint8* ptr = data + 1;
			data[0] = 0x1;
			serializeMesh(mesh, ptr);
			writeFileBin(file, data);
		}

		void serializeMesh(Mesh* mesh, uint8*& ptr) {
			memcpy(ptr, &(mesh->vertices.size), sizeof(uint64));
			ptr += sizeof(uint64);
			memcpy(ptr, &(mesh->indices.size), sizeof(uint64));
			ptr += sizeof(uint64);
			memcpy(ptr, mesh->vertices.data, mesh->vertices.size * sizeof(float));
			ptr += mesh->vertices.size * sizeof(float);
			memcpy(ptr, mesh->indices.data, mesh->indices.size * sizeof(uint16));
			ptr += mesh->indices.size * sizeof(uint16);
		}
	}
}
