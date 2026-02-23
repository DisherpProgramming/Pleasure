#pragma once

#include<iostream>
#include <array>


#include "EXTERNAL/GL/glew.h"
#include "EXTERNAL/GLFW/glfw3.h"

struct Vert2D {
    Vert2D(float thisX, float thisY) {
        x = thisX;
        y = thisY;
    }

    float x;
    float y;
};

class MeshIndexing {
public:
    void GetVerts(Vert2D *CornerA, Vert2D *CornerD);
    std::array<int, 6> GetVertOrder();
    std::array<GLuint, 3> BuffArrays();
private:
    std::array<float, 12> localVerts;
    std::array<int, 6> localIndices;
};
