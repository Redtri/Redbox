#include "World.h"
#include "../Engine.h"

void cWorld::update(float deltaTime)
{
    for (auto& actor : m_actors)
    {
        Vector randomPosition(1 + (rand() % WIN_WIDTH), 1 + (rand() % WIN_HEIGHT), 0.);
        actor->setPosition(randomPosition);
    }
}

void cWorld::addActor(cActor* t_newActor)
{
    if (m_actors.size() < m_actors.capacity())
    {
        m_actors.push_back(t_newActor);
    }
}
