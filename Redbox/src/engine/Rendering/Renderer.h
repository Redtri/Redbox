#pragma once

#include <GLFW/glfw3.h>
#include "../World/worldUtils.h"

#define DEBUG_CURSOR_SIZE 0.01f

struct GLFWwindow;

class cWorld;
class cRendererComponent;

class cRenderer
{
public:
    cRenderer() : m_window(nullptr), m_world(nullptr) {};

    void init(GLFWwindow* t_window);
    void initWorld(cWorld* t_World);

    void render();
    void renderWorld();
    void renderComponent(cRendererComponent* t_rendererComponent);

    // Draw functions
    void drawPoint(float x, float y, float t_size);
    void drawCube(float x, float y, float t_size);
    void drawSphere(float t_size);

    static void createVertexBuffer(unsigned int* t_VBO, Vector* t_buffer);
protected:
    void perspectiveGL(GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar);
protected:
    unsigned int vbo;
    GLFWwindow* m_window;
    cWorld* m_world;
};

