#include "inputManager.h"
#include <GLFW/glfw3.h>

cInputManager::cInputManager() :
    engineActionBindings()
{
 
}

cInputManager::~cInputManager()
{

}

void cInputManager::init(GLFWwindow* t_window)
{
    m_window = t_window;
    
    //TODO: should be fetched from a file
    const std::pair<const eEngineAction, int> newPair(eEngineAction::Exit, GLFW_KEY_ESCAPE);
    engineActionBindings.insert(newPair);

    GLFWkeyfun keyFunction;
    //TODO: Seems to be a workaround, and can only be set once. Find a better way to reference (*this).
    glfwSetWindowUserPointer(t_window, this);

    // Bind a callback to the key events of the main window
    glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mode)
    {
        //TODO: Seems to be a workaround, and can only be set once. Find a better way to reference (*this).
        auto self = static_cast<cInputManager*>(glfwGetWindowUserPointer(window));
        if (self)
        {
            if (action == GLFW_PRESS)
            {
                for (auto& actionBinding : self->engineActionBindings)
                {
                    if (key == actionBinding.second)
                    {
                        switch(actionBinding.first)
                        {
                            case eEngineAction::Exit:
                                glfwSetWindowShouldClose(window, GLFW_TRUE);
                            break;
                        }
                    }
                }
            }
        }
    });
}

void cInputManager::onKeyDown(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void cInputManager::callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{

}
