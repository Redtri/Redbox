
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Renderer.h"
#include <math.h>
#include "../World/World.h"
#include "../World/Actor/StaticMeshActor.h"
#include "../World/Components/RendererComponent.h"

void cRenderer::init(GLFWwindow* t_window)
{
    m_window = t_window;
    glEnable(GL_DEPTH_TEST); // Depth Testing
    glDepthFunc(GL_LEQUAL);
    glDisable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}

void cRenderer::initWorld(cWorld* t_World)
{
    m_world = t_World;
}

void cRenderer::render()
{
    // Scale to window size
    GLint windowWidth, windowHeight;
    glfwGetWindowSize(m_window, &windowWidth, &windowHeight);
    glViewport(0, 0, windowWidth, windowHeight);

    // Draw stuff
    glClearColor(0.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    perspectiveGL(60, (double)windowWidth / (double)windowHeight, 0.1, 100);

    glMatrixMode(GL_MODELVIEW_MATRIX);
    glTranslatef(0, 0, -5);

    //drawCube();
    //drawSquare((double)windowWidth/2,(double)windowHeight/2, 10);
    // Update Screen
    glfwSwapBuffers(m_window);
}

void cRenderer::renderWorld()
{
    if (m_world)
    {
        // Scale to window size
        GLint windowWidth, windowHeight;
        GLclampf red = 0.0f, green = 0.0f, blue = 0.0f, alpha = 0.0f;

        glfwGetWindowSize(m_window, &windowWidth, &windowHeight);
        glViewport(0, 0, windowWidth, windowHeight);

        // Draw stuff
        glClearColor(red, green, blue, alpha);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //glMatrixMode(GL_PROJECTION_MATRIX);
        //glLoadIdentity();
        //perspectiveGL(60, (double)windowWidth / (double)windowHeight, 0.1, 100);

        //glMatrixMode(GL_MODELVIEW_MATRIX);
        //glTranslatef(0, 0, -5);
        //glEnableVertexArrayAttrib(0);
        //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

        for (auto& actor : m_world->getActors())
        {
            if (actor)
            {
                if (cRendererComponent * rendererComponent = actor->getComponent<cRendererComponent>())
                {
                    renderComponent(rendererComponent);
                }
            }
        }
        glfwSwapBuffers(m_window);
        //glDisableVertexAttribArray(0);
    }
}

void cRenderer::renderComponent(cRendererComponent* t_rendererComponent)
{
    // TODO: implement modular triangle/primitive counts as this is only rendering triangles
    unsigned int VBO = t_rendererComponent->getVboId();
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(0);
}

void cRenderer::createVertexBuffer(unsigned int* t_VBO, Vector* t_buffer)
{
    glGenBuffers(1, t_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, (*t_VBO));
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vector) * 3, t_buffer, GL_STATIC_DRAW);
}

void cRenderer::perspectiveGL(GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar)
{
    const GLdouble pi = 3.1415926535897932384626433832795;
    GLdouble fW, fH;

    //fH = tan( (fovY / 2) / 180 * pi ) * zNear;
    fH = tan(fovY / 360 * pi) * zNear;
    fW = fH * aspect;

    glFrustum(-fW, fW, -fH, fH, zNear, zFar);
}

void cRenderer::drawPoint(float x, float y, float t_size)
{

}

void cRenderer::drawCube(float x, float y, float t_size)
{
    GLfloat vertices[] =
    {
        -1, -1, -1,   -1, -1,  1,   -1,  1,  1,   -1,  1, -1,
        1, -1, -1,    1, -1,  1,    1,  1,  1,    1,  1, -1,
        -1, -1, -1,   -1, -1,  1,    1, -1,  1,    1, -1, -1,
        -1,  1, -1,   -1,  1,  1,    1,  1,  1,    1,  1, -1,
        -1, -1, -1,   -1,  1, -1,    1,  1, -1,    1, -1, -1,
        -1, -1,  1,   -1,  1,  1,    1,  1,  1,    1, -1,  1
    };

    GLfloat colors[] =
    {
        0, 0, 0,   0, 0, 1,   0, 1, 1,   0, 1, 0,
        1, 0, 0,   1, 0, 1,   1, 1, 1,   1, 1, 0,
        0, 0, 0,   0, 0, 1,   1, 0, 1,   1, 0, 0,
        0, 1, 0,   0, 1, 1,   1, 1, 1,   1, 1, 0,
        0, 0, 0,   0, 1, 0,   1, 1, 0,   1, 0, 0,
        0, 0, 1,   0, 1, 1,   1, 1, 1,   1, 0, 1
    };

    static float alpha = 0;
    //attempt to rotate cube
    glRotatef(alpha, 0, 1, 0);
    glTranslatef(x, y, 0);

    /* We have a color array and a vertex array */
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);

    /* Send data : 24 vertices */
    glDrawArrays(GL_QUADS, 0, 24);

    /* Cleanup states */
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    alpha += 1;
}

void cRenderer::drawSphere(float t_size)
{

}