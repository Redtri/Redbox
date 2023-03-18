#pragma once
#include <GLFW/glfw3.h>
#include <map>

//TODO: Need to forward declare GLFWwindow but will cause conflict with cEngine's
// class GLFWwindow;

enum class eEngineAction
{
    None,
    Exit
};

class cInputManager
{
public:
    cInputManager();
    ~cInputManager();

    void init(GLFWwindow* t_window);
protected:
    void onKeyDown(GLFWwindow* window, int key, int scancode, int action, int mode);
    static void callback(GLFWwindow* window, int key, int scancode, int action, int mode);
protected:
    GLFWwindow* m_window;
    std::map<eEngineAction, int> engineActionBindings;
};
