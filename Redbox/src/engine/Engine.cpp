#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../publicDefinitions.hpp"
#include "Engine.h"
#include "Inputs/inputManager.h"
#include "Rendering/Renderer.h"
#include "World/World.h"
#include "World/Actor/StaticMeshActor.h"

cEngine::cEngine()
{

}

cEngine::~cEngine()
{
    delete m_inputManager;
    delete m_renderer;
    delete m_currentWorld;
}

bool cEngine::startupEngine()
{
    /* Initialize the library */
    if (!glfwInit())
        return (bool)-1;

    /* Create a windowed mode window and its OpenGL context */
    m_window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "Redbox", NULL, NULL);
    if (!m_window)
    {
        stopEngine();
        return false;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(m_window);
    glfwSetWindowAttrib(m_window, GLFW_RESIZABLE, GLFW_TRUE);

    glewInit();

    if (m_inputManager = new cInputManager())
    {
        m_inputManager->init(m_window);
    }

    if (m_renderer = new cRenderer())
    {
        m_renderer->init(m_window);
    }

    if (m_currentWorld = new cWorld())
    {
        // Initialize world if needed
        for (int i = 0; i < 1; ++i)
        {
            Vector randomPosition(1.+(rand() % WIN_WIDTH), 1. + (rand() % WIN_HEIGHT), 0.);
            m_currentWorld->addActor(new cStaticMeshActor(randomPosition, eShape::Cube, 10.f));
        }
    }

    if (m_renderer)
    {
        m_renderer->initWorld(m_currentWorld);
    }

    return true;
}

int cEngine::update()
{
    if (m_currentWorld)
    {
        m_currentWorld->update(0.0f);
    }

    if (m_renderer)
    {
        m_renderer->renderWorld();
    }

    /* Poll for and process events */
    glfwPollEvents();
    int shouldMainWindowClose = glfwWindowShouldClose(m_window);
    if (shouldMainWindowClose)
    {
        stopEngine();
    }
    return(!shouldMainWindowClose);
}

void cEngine::stopEngine()
{
    glfwTerminate();
}