#pragma once

#include "Actor.h"
#include "../Components/RendererComponent.h"

typedef enum eShape
{
    None,
    Cube,
    Sphere
} eShape;

class cStaticMeshActor : public cActor
{
public:
    cStaticMeshActor(Vector t_pos);
    cStaticMeshActor(Vector t_pos, eShape t_shape, float t_size);

    eShape getShape() const { return m_shape; }
    float getSize() const { return m_size; }

protected:
    eShape m_shape;
    float m_size;
};

