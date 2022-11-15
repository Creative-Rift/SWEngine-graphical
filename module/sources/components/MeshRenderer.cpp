/*
** ShipWreck Engine , 2022
** Mesh.cpp
*/

#include "MeshRenderer.hpp"

#include <utility>
#include "OpenGLModule.hpp"

sw::MeshRenderer::MeshRenderer(sw::GameObject &gameObject, std::string name) :
sw::Component(gameObject),
model(sw::OpenResources::m_nmodel[std::move(name)])
{}

sw::MeshRenderer &sw::MeshRenderer::attachLight(std::string lightName)
{
    if (m_lights.size() >= MAX_LIGHT)
        return (*this);
    auto& newLight = m_gameObject.scene().getGameObject(lightName).getComponent<sw::Light>("LightManager");

    m_lights.emplace_back(newLight);
    return (*this);
}

sw::MeshRenderer &sw::MeshRenderer::attachLight(sw::Light &light)
{
    if (m_lights.size() >= MAX_LIGHT)
        return (*this);
    m_lights.emplace_back(light);
    return (*this);
}

sw::MeshRenderer &sw::MeshRenderer::detachLight(std::string lightName)
{
    int index = 0;

    for (auto& light : m_lights) {
        if (light.value().name() == lightName)
            m_lights[index].erase();
        index++;
    }
    return (*this);
}

sw::MeshRenderer &sw::MeshRenderer::detachLight(int index)
{
    m_lights[index].erase();
    return (*this);
}