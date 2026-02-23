//External Includes
#include <iostream>


//Game Includes
#include "Game/Mesh/MeshIndexing.h"



void MeshIndexing::GetVerts(Vert2D *CornerA, Vert2D *CornerD) { //(-0.5f, -0.5f) (0.5f,  0.5f)
    std::array<float, 12> Verts = {
        CornerA->x, CornerA->y, 0.0f, //Bottom Left Corner -> Corner A
        -CornerA->x, CornerA->y, 0.0f,  //Bottom Right Corner -> Corner B
        -CornerD->x, CornerD->y, 0.0f,  //Top Left Corner -> Corner C
        CornerD->x, CornerD->y, 0.0f  //Top Right Corner -> Corner D
    };
    
    localVerts = Verts;


    //for(int i = 0; i < localVerts.size(); i++) {
    //    std::cout << "Loca vert is " << localVerts[i] << ". ";
    //}

    //return localVerts;
}

std::array<int, 6> MeshIndexing::GetVertOrder() {
    std::array<int, 6> Indices = {
        0,1, 2,
        2,1,3
    };
    std::cout << "HI";
    localIndices = Indices;
    return Indices;

    std::cout << localVerts.data();
}

std::array<GLuint, 3> MeshIndexing::BuffArrays() {
    //[CREATE] -> BUFFERS
    std::array<GLuint, 3> Obj;
    GLuint vbo, vao, ebo;

    Obj[0] = vao;
    Obj[1] = vbo;
    Obj[2] = ebo;

    glGenVertexArrays(1, &Obj[0]);
    glGenBuffers(1, &Obj[1]); //Upload refrence of vertex data to gpu
    glGenBuffers(1, &Obj[2]);
    glBindVertexArray(Obj[0]);
    glBindBuffer(GL_ARRAY_BUFFER, Obj[1]); //Makes 'vbo' the active array buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Obj[2]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(localIndices), &localIndices, GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, sizeof(localVerts), &localVerts, GL_STATIC_DRAW); //Upload vertex data to gpu
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    return Obj;
}