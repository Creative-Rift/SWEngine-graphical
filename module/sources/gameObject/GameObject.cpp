/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2022
 * Software Engine Project
 *
 * Author:
 * Guillaume S.
 * File name:
 * GameObject.inl
 *
 * Description:
 */

#include "gameObject/GameObject.hpp"
#include "components/Transform.hpp"

sw::GameObject::GameObject(const std::string& GameObjectName, sw::Scene& sceneRef)
        :   m_isActive(true),
            m_name(GameObjectName),
            m_scene(sceneRef),
            m_transform(std::make_shared<Transform>(*this)),
            m_parent(),
            m_childrenMap(),
            id(-1)
{}

sw::GameObject::GameObject(const std::string& gameObjectName, sw::Scene& sceneRef, bool isActive)
        :   m_isActive(isActive),
            m_name(gameObjectName),
            m_scene(sceneRef),
            m_transform(std::make_shared<Transform>(*this)),
            m_parent(),
            m_childrenMap(),
            id(-1)

{}

void sw::GameObject::addChild(const std::string& entityName)
{
    auto& entity = m_scene.getGameObject(entityName);

    entity.transform().setPosition(transform().getPosition());
    entity.transform().setRotation(transform().getAngle(), transform().getRotationAxis().x, transform().getRotationAxis().y, transform().getRotationAxis().z);
    entity.transform().setScale(transform().getScale());
    entity.m_parent = *this;
    m_childrenMap.insert({entity.m_name, entity});
}

void sw::GameObject::removeChild(const std::string& entityName)
{
    auto& entity = m_scene.getGameObject(entityName);

    entity.m_parent.erase();
    m_childrenMap.erase(entityName);
}

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

sw::Transform &sw::GameObject::transform()
{
    return (*m_transform);
}

YAML::Node sw::GameObject::save() const
{
    YAML::Node node;

    node["name"] = name();
    node["active"] = m_isActive;
    node["transform"] = m_transform->save();
    if (m_parent.hasValue())
        node["parent"] = m_parent.value().name();

    return (node);
}

void sw::GameObject::load(YAML::Node &node)
{
    auto transform = node["transform"];
    m_isActive = node["active"].as<bool>();
    m_transform->setPosition(transform["position"][0].as<float>(), transform["position"][1].as<float>(), transform["position"][2].as<float>());
    m_transform->setScale(transform["scale"][0].as<float>(), transform["scale"][1].as<float>(), transform["scale"][2].as<float>());
    m_transform->setRotation(transform["angle"].as<float>(), transform["rotation_axis"][0].as<float>(), transform["rotation_axis"][1].as<float>(), transform["rotation_axis"][2].as<float>());
}