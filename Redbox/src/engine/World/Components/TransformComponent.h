#pragma once

#include "../worldUtils.h"
#include "ActorComponent.h"

class cTransformComponent : public cActorComponent
{
public:
    cTransformComponent(cActor* t_owner, Vector t_relativePos = Vector(0.f), Vector t_relativeScale = Vector(0.f));

    inline void setRelativePosition(Vector t_pos) { m_relativePosition = t_pos; }
    inline Vector getRelativePosition() const { return m_relativePosition; }

    inline void setRelativeScale(Vector t_scale) { m_relativeScale = t_scale; }
    inline Vector getRelativeScale() const { return m_relativeScale; }
protected:
    // TODO: Encapsulate this into a Transform object
    // TODO: Add rotation
    Vector m_relativePosition;
    Vector m_relativeScale;
};

