/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Camera.cpp
** Description: [CHANGE]
*/

#include "Transform.hpp"
#include "dependencies/glm/gtc/matrix_transform.hpp"
#include "GameObject.hpp"
#include "CameraManager.hpp"
#include "OpenGLModule.hpp"
#include "Vector3.hpp"

#include "Camera.hpp"

sw::Camera::Camera(sw::GameObject &gameObject) :
sw::Component(gameObject),
m_type(Projection::ORTHOGRAPHIC),
m_fov(45),
m_size(1),
m_clippingNear(-1.0f),
m_clippingFar(100.0f),
m_view(1.0),
m_up(),
m_front(),
m_pitch(0.0f),
m_yaw(-90.0f)
{
}

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

sw::Camera &sw::Camera::setPitch(float newPitch)
{
    m_pitch = newPitch;
    return (*this);
}

sw::Camera &sw::Camera::setYaw(float newYaw)
{
    m_yaw = newYaw;
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

glm::mat4 sw::Camera::getView()
{
    sw::ConcreteComponent auto& transform = m_gameObject.transform();
    glm::mat4 matrix = glm::mat4(1.0f);

    matrix = glm::translate(matrix, glm::vec3(-transform.getPosition().x, -transform.getPosition().y, -transform.getPosition().z));
    matrix = glm::rotate(matrix, glm::radians(transform.getAngle()), glm::vec3(transform.getRotationAxis().x, transform.getRotationAxis().y, transform.getRotationAxis().z));
    matrix = glm::scale(matrix, glm::vec3(transform.getScale().x, transform.getScale().y, transform.getScale().z));

    updateVectors();

    glm::vec3 vpos = {transform.getPosition().x, transform.getPosition().y, transform.getPosition().z};
    if (m_type == Projection::PERSPECTIVE)
        matrix = glm::lookAt(vpos, vpos + m_front, m_up);

    return (matrix);
}

float sw::Camera::getPitch() const
{
    return (m_pitch);
}

float sw::Camera::getYaw() const
{
    return (m_yaw);
}

glm::vec3 sw::Camera::getFront() const
{
    return (m_front);
}

glm::vec3 sw::Camera::getRight() const
{
    return (m_right);
}

void sw::Camera::updateVectors()
{
    glm::vec3 front;
    front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    front.y = sin(glm::radians(m_pitch));
    front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_front = glm::normalize(front);
    m_right = glm::normalize(glm::cross(m_front, glm::vec3(0.0f, 1.0f, 0.0f)));
    m_up    = glm::normalize(glm::cross(m_right, m_front));
}

YAML::Node sw::Camera::save() const
{
    YAML::Node node;

    node["entity_name"] = name();
    node["fov"] = m_fov;
    node["size"] = m_size;
    node["clipNear"] = m_clippingNear;
    node["clipFar"] = m_clippingFar;
    node["type"] = m_type == ORTHOGRAPHIC ? 1 : 0;
    return (node);
}