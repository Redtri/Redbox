#pragma once

#define WIN_HEIGHT 1080
#define WIN_WIDTH 1920

struct GLFWwindow;
class cInputManager;
class cRenderer;
class cWorld;

class cEngine
{
public:
    cEngine();
    ~cEngine();

    virtual bool startupEngine();
    virtual int update();
    virtual void stopEngine();
protected:
    GLFWwindow* m_window;
    cInputManager* m_inputManager;
    cRenderer* m_renderer;

    cWorld* m_currentWorld;
};

