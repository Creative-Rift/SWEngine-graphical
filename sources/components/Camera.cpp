/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Camera.cpp
** Description: [CHANGE]
*/

#include "Transform.hpp"
#include "dependencies/glm/gtc/matrix_transform.hpp"

#include "Camera.hpp"

sw::Camera::Camera(sw::Entity &entity) :
sw::Component(entity),
m_type(Projection::ORTHOGRAPHIC),
m_fov(45),
m_size(1),
m_clippingNear(0.1f),
m_clippingFar(1000.0f),
m_view(1.0)
{}

sw::Camera& sw::Camera::setProjection(Projection projection)
{
    m_type = projection;
    return (*this);
}

sw::Camera& sw::Camera::setFov(float fov)
{
    m_fov = fov;
    return (*this);
}

sw::Camera &sw::Camera::setSize(float size)
{
    m_size = size;
    return (*this);
}

sw::Camera &sw::Camera::setClipping(float near, float far)
{
    m_clippingNear = near;
    m_clippingFar = far;
    return (*this);
}

sw::Camera &sw::Camera::setClippingNear(float near)
{
    m_clippingNear = near;
    return (*this);
}

sw::Camera &sw::Camera::setClippingFar(float far)
{
    m_clippingFar = far;
    return (*this);
}

const glm::mat4 &sw::Camera::getProjection()
{
    if (m_type == Projection::ORTHOGRAPHIC)
        m_view = glm::ortho(0.0f, 1920.0f * m_size, 1080.0f * m_size, 0.0f, m_clippingNear, m_clippingFar);
    else
        m_view = glm::perspective(m_fov, 1920.0f / 1080.0f, m_clippingNear, m_clippingFar);
    return (m_view);
}

const glm::mat4 &sw::Camera::getView() const
{
    sw::ConcreteComponent auto& transform = m_entity.getComponent<sw::Transform>("TransformManager");

    return (transform.getMatrix());
}