#pragma once
#include <vector>
#include "Actor/Actor.h"
#include "worldUtils.h"

#define MAX_ACTORS 100

class cWorld
{
public:
    cWorld() : m_actors()
    {
        m_actors.reserve(MAX_ACTORS);
    };

    ~cWorld()
    {
        for (auto& actor : m_actors)
        {
            delete actor;
        }
        m_actors.clear();
    }

    void update(float deltaTime);

    void addActor(cActor* t_newActor);

    const std::vector<cActor*>& getActors() const { return m_actors; }
protected:
    std::vector<cActor*> m_actors;
};

