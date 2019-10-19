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
				uint32 offset = 1;
				uint16 vertexCount = 0;
				memcpy(&vertexCount, data + offset, sizeof(uint16));
				offset += sizeof(uint16);
				uint16 indexCount = 0;
				memcpy(&indexCount, data + offset, sizeof(uint16));
				offset += sizeof(uint16);
				buffer<float> vertices(vertexCount);
				memcpy(vertices.data, data + offset, vertexCount * sizeof(float));
				offset += vertexCount * sizeof(float);
				buffer<uint16> indices(indexCount);
				memcpy(indices.data, data + offset, indexCount * sizeof(uint16));
				//offset += indexCount * sizeof(uint16);
				return new Mesh(vertices, indices);
			} else if (data[0] == 0x1) {
				uint32 offset = 1;
				uint64 vertexCount = 0;
				memcpy(&vertexCount, data + offset, sizeof(uint64));
				offset += sizeof(uint64);
				uint64 indexCount = 0;
				memcpy(&indexCount, data + offset, sizeof(uint64));
				offset += sizeof(uint64);
				buffer<float> vertices(vertexCount);
				memcpy(vertices.data, data + offset, vertexCount * sizeof(float));
				offset += vertexCount * sizeof(float);
				buffer<uint16> indices(indexCount);
				memcpy(indices.data, data + offset, indexCount * sizeof(uint16));
				//offset += indexCount * sizeof(uint16);
				return new Mesh(vertices, indices);
			}
			return nullptr;
		}

		void writeMesh(const FileHandle& file, Mesh* mesh) {
			uint32 size = 1;
			size += sizeof(uint16);
			size += sizeof(uint16);
			size += mesh->vertices.size * sizeof(float);
			size += mesh->indices.size * sizeof(uint16);
			buffer<uint8> data(size);
			uint32 offset = 1;
			data[0] = 0x1;
			serializeMesh(mesh, data, offset);
			writeFileBin(file, data);
		}

		buffer<uint8> serializeMesh(Mesh* mesh, buffer<uint8>& data, uint32& offset) {
			memcpy(data + offset, &(mesh->vertices.size), sizeof(uint64));
			offset += sizeof(uint64);
			memcpy(data + offset, &(mesh->indices.size), sizeof(uint64));
			offset += sizeof(uint64);
			memcpy(data + offset, mesh->vertices.data, mesh->vertices.size * sizeof(float));
			offset += mesh->vertices.size * sizeof(float);
			memcpy(data + offset, mesh->indices.data, mesh->indices.size * sizeof(uint16));
			offset += mesh->indices.size * sizeof(uint16);
			return data;
		}
	}
}
