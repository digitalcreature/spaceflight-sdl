#pragma once

#include "Graphics.hpp"
#include <vector>
#include <cml/vector.h>

class Mesh {
	private:
		guint vertBufferName;
		guint indexBufferName;
		std::vector<cml::vector3f> verts;
		std::vector<guint> indices;
	public:
		Mesh();
		~Mesh();
		void render();
		size_t getVertCount() { return verts.size(); }
		void setVertCount(size_t count) { verts.resize(count); }
		size_t getIndexCount() { return indices.size(); }
		void setIndexCount(size_t count) { indices.resize(count); }
		cml::vector3f& vert(size_t i) { return verts[i]; }
		guint& index(size_t i) { return indices[i]; }
		void update();
};