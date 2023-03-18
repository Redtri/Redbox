#include "StaticMeshActor.h"

cStaticMeshActor::cStaticMeshActor(Vector t_pos) :
    cActor(t_pos), m_shape(None)
{

}

cStaticMeshActor::cStaticMeshActor(Vector t_pos, eShape t_shape, float t_size) :
    cActor(t_pos), m_shape(t_shape), m_size(t_size)
{
    addComponent(new cRendererComponent(this));
}
