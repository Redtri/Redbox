#include "Actor.h"

cActor::cActor(Vector t_pos) : m_position(t_pos)
{
    m_components.reserve(MAX_COMPONENTS);
}

cActor::~cActor()
{
    for (auto& component : m_components)
    {
        delete component;
    }
}

void cActor::addComponent(cActorComponent* t_component)
{
    if (t_component && m_components.size() < MAX_COMPONENTS)
    {
        m_components.push_back(t_component);
    }
}
