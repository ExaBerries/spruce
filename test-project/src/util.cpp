#include <util.h>

aowner<Mesh> createCube(vec3f size) {
	uint16 i = 0;
	buffer<float> vertices(24);
	vertices[i++] = size.x / -2;
	vertices[i++] = size.y / -2;
	vertices[i++] = size.z / 2;

	vertices[i++] = size.x / 2;
	vertices[i++] = size.y / -2;
	vertices[i++] = size.z / 2;

	vertices[i++] = size.x / 2;
	vertices[i++] = size.y / 2;
	vertices[i++] = size.z / 2;

	vertices[i++] = size.x / -2;
	vertices[i++] = size.y / 2;
	vertices[i++] = size.z / 2;

	vertices[i++] = size.x / -2;
	vertices[i++] = size.y / -2;
	vertices[i++] = size.z / -2;

	vertices[i++] = size.x / 2;
	vertices[i++] = size.y / -2;
	vertices[i++] = size.z / -2;

	vertices[i++] = size.x / 2;
	vertices[i++] = size.y / 2;
	vertices[i++] = size.z / -2;

	vertices[i++] = size.x / -2;
	vertices[i++] = size.y / 2;
	vertices[i++] = size.z / -2;
	buffer<uint16> indices(36);
	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
	indices[3] = 2;
	indices[4] = 3;
	indices[5] = 0;
	indices[6] = 1;
	indices[7] = 5;
	indices[8] = 6;
	indices[9] = 6;
	indices[10] = 2;
	indices[11] = 1;
	indices[12] = 7;
	indices[13] = 6;
	indices[14] = 5;
	indices[15] = 5;
	indices[16] = 4;
	indices[17] = 7;
	indices[18] = 4;
	indices[19] = 0;
	indices[20] = 3;
	indices[21] = 3;
	indices[22] = 7;
	indices[23] = 4;
	indices[24] = 4;
	indices[25] = 5;
	indices[26] = 1;
	indices[27] = 1;
	indices[28] = 0;
	indices[29] = 4;
	indices[30] = 3;
	indices[31] = 2;
	indices[32] = 6;
	indices[33] = 6;
	indices[34] = 7;
	indices[35] = 3;
	return newaown<Mesh>(vertices, indices);
}

aowner<Mesh> createPlane(vec2f size) {
	uint16 i = 0;
	buffer<float> vertices(12);
	vertices[i++] = size.x / -2;
	vertices[i++] = 0;
	vertices[i++] = size.y / -2;
	vertices[i++] = size.x / -2;
	vertices[i++] = 0;
	vertices[i++] = size.y / 2;
	vertices[i++] = size.x / 2;
	vertices[i++] = 0;
	vertices[i++] = size.y / -2;
	vertices[i++] = size.x / 2;
	vertices[i++] = 0;
	vertices[i++] = size.y / 2;
	buffer<uint16> indices(6);
	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
	indices[3] = 2;
	indices[4] = 3;
	indices[5] = 1;
	return newaown<Mesh>(vertices, indices);
}

aowner<Mesh> createScreenQuad() {
	uint16 i = 0;
	buffer<float> vertices(20);
	vertices[i++] = -1;
	vertices[i++] = -1;
	vertices[i++] = 0;
	vertices[i++] = 0;
	vertices[i++] = 0;

	vertices[i++] = -1;
	vertices[i++] = 1;
	vertices[i++] = 0;
	vertices[i++] = 0;
	vertices[i++] = 1;

	vertices[i++] = 1;
	vertices[i++] = -1;
	vertices[i++] = 0;
	vertices[i++] = 1;
	vertices[i++] = 0;

	vertices[i++] = 1;
	vertices[i++] = 1;
	vertices[i++] = 0;
	vertices[i++] = 1;
	vertices[i++] = 1;
	buffer<uint16> indices(6);
	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
	indices[3] = 2;
	indices[4] = 3;
	indices[5] = 1;
	return newaown<Mesh>(vertices, indices);
}
