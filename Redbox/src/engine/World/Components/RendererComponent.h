#pragma once

#include "TransformComponent.h"

class cRendererComponent : public cTransformComponent
{
public:
    cRendererComponent(cActor* t_owner, Vector t_relativePos = Vector(0.f), Vector t_relativeScale = Vector(0.f));

    inline unsigned int getVboId() const { return m_VboId; }
public:
    static const int NB_VERTICES_SQUARE = 4;
    static const int NB_VERTICES_TRIANGLE = 3;
protected:
    unsigned int m_VboId;
    Vector m_vertices[NB_VERTICES_TRIANGLE];
};

