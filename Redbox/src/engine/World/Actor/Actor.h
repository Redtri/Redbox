#pragma once

#include "../worldUtils.h"
#include <vector>

class cActorComponent;

class cActor
{
public:
    cActor(Vector t_pos);
    ~cActor();

    void addComponent(cActorComponent* t_component);
    
    template<class T>
    T* getComponent();

    inline void setPosition(Vector t_pos) { m_position = t_pos; }
    inline Vector getPosition() const { return m_position; }

public:
    static const int MAX_COMPONENTS = 50;
protected:
    Vector m_position;
    std::vector<cActorComponent*> m_components;
private:
};


template<class T>
inline T* cActor::getComponent()
{
    for (auto& component : m_components)
    {
        if (T* castResult = static_cast<T*>(component))
        {
            return castResult;
        }
    }
    return nullptr;
}