#pragma once

class cActor;

class cActorComponent
{
public:
    cActorComponent(cActor* t_owner) : m_owner(t_owner) {}

    inline cActor* getOwner() const { return m_owner; }
protected:
    cActor* m_owner;
};

