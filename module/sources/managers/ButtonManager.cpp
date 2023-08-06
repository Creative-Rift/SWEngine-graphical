/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2023
** Author: Guillaume S.
** File name: Entity.cpp
** Description: [CHANGE]
*/

#include "gameObject/GameObject.hpp"
#include "components/Components.hpp"
#include "Window.hpp"

#include "ButtonManager.hpp"

YAML::Node sw::ButtonManager::save() const
{
    return AManager::save();
}

void sw::ButtonManager::onLoad(YAML::Node &node)
{
    AManager::onLoad(node);
}

void sw::ButtonManager::onUpdate()
{
    sw::Vector2f mousePos = sw::getMousePosition();

    for (auto&[_, obj]: m_components) {

        sw::Vector3f pos = obj->gameObject().transform().getGlobalPosition();
        auto width = obj->m_sprite.value().getMaterial().texture->getWidth();
        auto height = obj->m_sprite.value().getMaterial().texture->getHeight();

        if (mousePos.x >= pos.x && mousePos.x < pos.x + width * obj->gameObject().transform().getScale().x
            && mousePos.y >= pos.y && mousePos.y < pos.y + height * obj->gameObject().transform().getScale().y) {
            obj->m_sprite.value().setColor(sw::Color{1.0f, 1.0f, 1.0f});
            if (!obj->m_hover)
                obj->m_audio.value().play(std::rand() % 3);
            obj->m_hover = true;
            if (sw::isMouseButtonPressed(sw::MouseBtn::Button_left))
                if (obj->m_callback) {
                    obj->m_audio.value().play(3);
                    obj->m_callback(obj.get());
                }
        } else {
            obj->m_sprite.value().setColor(sw::Color{100.0f / 255.0f, 100.0f / 255.0f, 100.0f / 255.0f});
            obj->m_hover = false;
        }
    }
}
