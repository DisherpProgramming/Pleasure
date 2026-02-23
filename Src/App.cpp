#define GLFW_DLL

//External Inncludes
#include <cstddef>
#include <EXTERNAL/GL/glew.h>
#include <EXTERNAL/GLFW/glfw3.h>


//Game Includes
#include "Game/Mesh/BasicMesh.h"
#include "Game/Mesh/MeshIndexing.h"

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Pleasure", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glewInit();
    BasicMesh basicMesh;
    MeshIndexing Shapes;
    Vert2D cornerA = Vert2D(-0.5f, -0.5f);
    Vert2D cornerD = Vert2D(0.5f, 0.5f);

    //[DATA] -> Points
    basicMesh.CreateRectangle(new Vert2D(-0.5f, -0.5f), new Vert2D(0.5f, 0.5f));
    std::array<int, 6> Indices = Shapes.GetVertOrder();
    std::array<unsigned int, 3> BuffArrays = Shapes.BuffArrays(); 

    //[DATA] ->Shaders
    const char *vertSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

    const char *fragSource = "#version 330 core\n"
    "out vec4 FragColor;\n"

    "void main()\n"
    "{\n"
        "FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";


    //[CREATE] -> BUFFERS



    //[CREAT] -> SHADERS
    GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(vertShader, 1, &vertSource, NULL);
    glShaderSource(fragShader, 1, &fragSource, NULL);
    glCompileShader(vertShader);
    glCompileShader(fragShader);

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertShader);
    glAttachShader(shaderProgram, fragShader);
    glLinkProgram(shaderProgram);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        

        glUseProgram(shaderProgram);
        glBindVertexArray(BuffArrays[0]);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, BuffArrays[2]);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        
        
        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}