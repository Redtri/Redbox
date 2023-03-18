#include "TransformComponent.h"

cTransformComponent::cTransformComponent(cActor* t_owner, Vector t_relativePos /*= Vector(0.f, 0.f) */, Vector t_relativeScale /*= Vector(0.f, 0.f) */) :
    cActorComponent(t_owner), m_relativePosition(t_relativePos), m_relativeScale(t_relativeScale)
{

}