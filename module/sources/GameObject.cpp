/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2022
 * Software Engine Project
 *
 * Author:
 * Guillaume S.
 * File name:
 * GameObject.cpp
 *
 * Description:
 */

#include "GameObject.hpp"

std::string sw::GameObject::name() const
{
    return (m_name);
}

void sw::GameObject::deleteComponent(const std::string& managerName)
try
{
    return (m_scene.getManager(managerName).deleteComponent(m_name));
}
catch (sw::Error& error)
{
    std::string code = error.getCode();
    if (code == "4314")
        throw sw::Error(sw::Log::error514(FUNCTION, m_name, managerName));
    else
        throw error;
}

void sw::GameObject::setLayer(const std::string& managerName, int layer)
try
{
    return (m_scene.getManager(managerName).setLayer(m_name, layer));
}
catch (sw::Error& error)
{
    std::string code = error.getCode();
    if (code == "4314")
        throw sw::Error(sw::Log::error514(FUNCTION, m_name, managerName));
    else
        throw error;
}