/*
    @brief      NWPU C++ Homework 2
    @author     Kvar_ispw17, Mion
    @contact    Mion is super cute so you should ask him  ฅ^•ﻌ•^ฅ
*/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);


const unsigned int SCR_WIDTH = 600;
const unsigned int SCR_HEIGHT = 512;

float v[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5, 0.0f,
    -0.5f, 0.5f, 0.0f,
    0.5f, 0.5f, 0.0f
}; // I want to draw a square !!

const char* vertexShaderSource = 
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main() { gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\0"; // ??? can't we write GLSL outside cpp ???

int main()
{

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // OpenGL 3.3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // core profile programming mode


    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL Homework 2", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    unsigned int VBO; // vertex buffer object
    glGenBuffers(1, &VBO); // give id "VBO" a buffer! 
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // bind "VBO" as CURRENT array buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(v), v, GL_STATIC_DRAW); // send v to VBO which is the CURRENT array buffer



    while (!glfwWindowShouldClose(window))
    {

        processInput(window);

        glClearColor(1, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}


void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}