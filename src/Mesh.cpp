
#include "Mesh.hpp"

Mesh::Mesh() :
	verts(0), indices(0) {
	glGenBuffers(1, &vertBufferName);
	glGenBuffers(1, &indexBufferName);
}

Mesh::~Mesh() {
	glDeleteBuffers(1, &vertBufferName);
	glDeleteBuffers(1, &indexBufferName);
}

void Mesh::render() {
	glEnableClientState(GL_VERTEX_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, vertBufferName);
	glVertexPointer(3, GL_FLOAT, 0, NULL);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferName);
	glDrawElements(GL_TRIANGLES, getIndexCount(), GL_UNSIGNED_INT, NULL);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void Mesh::update() {
	glBindBuffer(GL_ARRAY_BUFFER, vertBufferName);
	size_t vertCount = getVertCount();
	glBufferData(GL_ARRAY_BUFFER, vertCount * sizeof(cml::vector3f), &verts.front(), GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferName);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, getIndexCount() * sizeof(GLuint), &indices.front(), GL_DYNAMIC_DRAW);

}
