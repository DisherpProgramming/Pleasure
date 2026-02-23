MeshIndexing:
    g++ -std=c++17 -IIncludes -c Src/Game/Mesh/MeshIndexing.cpp -o Obj/Mesh/MeshIndexing.o

BasicMesh:
    g++ -std=c++17 -IIncludes -c Src/Game/Mesh/BasicMesh.cpp -o Obj/Mesh/BasicMesh.o

build:
    g++ -std=c++17 -IIncludes Src/App.cpp Obj/Mesh/*.o -L. -lglew32 -lglfw3 -lopengl32 -lgdi32 -o Pleasure

play:
    ./Pleasure.exe

rm:
    rm ./Pleasure.exe
    rm Obj/Mesh/*.o