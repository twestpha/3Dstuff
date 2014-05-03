#pragma once
#include "Camera.h"
#include "Vertex.h"

class Face{
private:
	Vertex s, t, u; // Vertices s, t, and u
	int r, g, b;    // RGB values r, g, and b
public:
	Face(void);
	Face( Vertex, Vertex, Vertex, int, int, int);
	~Face(void);
	void draw(Camera);
};

