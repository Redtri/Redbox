#include "RendererComponent.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../../Rendering/Renderer.h"
#include <math.h>

cRendererComponent::cRendererComponent(cActor* t_owner, Vector t_relativePos /*= Vector(0.f, 0.f) */, Vector t_relativeScale /*= Vector(0.f, 0.f) */) :
    cTransformComponent(t_owner, t_relativePos, t_relativeScale)
{

    m_vertices[0] = Vector(-1., -1., 0.);
    m_vertices[1] = Vector(0., 1., 0.);
    m_vertices[2] = Vector(1., -1., 0.);
    cRenderer::createVertexBuffer(&m_VboId, m_vertices);
}