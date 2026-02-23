//External Includes

//Game Includes
#include "Game/Mesh/BasicMesh.h"
#include "Game/Mesh/MeshIndexing.h"


void BasicMesh::CreateRectangle(Vert2D *CornerA, Vert2D *CornerD) {
    MeshIndexing MeshIndex;

    std::cout << "CornerA is: " << CornerA->x << "." << CornerA->y << std::endl;
    std::cout << "CornerD is: " << CornerD->x << "." << CornerD->y << std::endl;

    MeshIndex.GetVerts(CornerA, CornerD);
}