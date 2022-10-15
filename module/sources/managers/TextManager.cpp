/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: SpriteManager.cpp
** Description: [CHANGE]
*/

#include "dependencies/glad/glad.h"

#include "managers/TextManager.hpp"

#include "components/Transform.hpp"
#include "components/Camera.hpp"

#include "dependencies/glm/glm.hpp"
#include "dependencies/glm/gtc/matrix_transform.hpp"
#include "dependencies/glm/gtc/type_ptr.hpp"
#include "GameObject.hpp"

#include <iostream>

void sw::TextManager::onUpdate()
{
    unsigned int VAO, VBO;

    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    sw::ConcreteComponent auto& camera = m_scene.getGameObject("MainCamera").getComponent<sw::Camera>("CameraManager");

    for (auto& [_, name] : m_componentsLayers) {
        auto& object = m_components[name];
        if (!object->isActive() || !object->gameObject().isActive())
            continue;
        //sw::ConcreteComponent auto& transform = object->entity().getComponent<sw::Transform>("TransformManager");

        auto &shader = object->getShader();
        glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(1920), 0.0f, static_cast<float>(1080));
        shader->useShader();
        shader->setUniMat4("projection", projection);

        auto &tmp_color = object->getColor();
        object->getShader()->setUniFloat3("textColor", tmp_color.r, tmp_color.g, tmp_color.b);
        glActiveTexture(GL_TEXTURE0);

        auto &text = object->getText();
        auto &charmap = object->getFont()->getCharacters();
        auto &txtpos = object->getPos();
        auto &scale = object->getScale();
        std::string::const_iterator c;
        float x = txtpos.first;
        float y = txtpos.second;
        for (c = text.begin(); c != text.end(); c++) 
        {
            sw::Font::Character ch = charmap.at(*c);

            float xpos = x + ch.Bearing.x * scale;
            float ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

            float w = ch.Size.x * scale;
            float h = ch.Size.y * scale;

            // update VBO for each character
            float vertices[6][4] = {
                { xpos,     ypos + h,   0.0f, 0.0f },            
                { xpos,     ypos,       0.0f, 1.0f },
                { xpos + w, ypos,       1.0f, 1.0f },

                { xpos,     ypos + h,   0.0f, 0.0f },
                { xpos + w, ypos,       1.0f, 1.0f },
                { xpos + w, ypos + h,   1.0f, 0.0f }           
            };

            // render glyph texture over quad
            glBindTexture(GL_TEXTURE_2D, ch.TextureID);
            glBindVertexArray(VAO);

            // update content of VBO memory
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

            glBindBuffer(GL_ARRAY_BUFFER, 0);
            // render quad
            glDrawArrays(GL_TRIANGLES, 0, 6);
            // bitshift by 6 to get value in pixels (2^6 = 64 (divide amount of 1/64th pixels by 64 to get amount of pixels))
            x += (ch.Advance >> 6) * scale;
            glBindVertexArray(0);
            glBindTexture(GL_TEXTURE_2D, 0);
        }
    }
    glDisable(GL_CULL_FACE);
    glDisable(GL_BLEND);
}

YAML::Node sw::TextManager::save() const
{
    YAML::Node node;

    node["name"] = name();
    node["valid"] = true;
    node["active"] = m_isActive;
    for (auto &[_, component]: m_components)
        node["components"].push_back(component->save());
    for (auto &[layer, name]: m_componentsLayers) {
        YAML::Node ye;
        ye["name"] = name;
        ye["index"] = layer;
        node["layer"].push_back(ye);
    }
    return (node);
}

void sw::TextManager::onLoad(YAML::Node& node) {
    for (auto component: node["components"]) {
        sw::Text &text = createComponent(component["entity_name"].as<std::string>());
        text.m_text = component["text"].as<std::string>();
        //text.m_shader.load(component["shader"]);
        text.m_color.load(component["color"]);
        text.m_pos.first = component["posx"].as<float>();
        text.m_pos.second = component["posy"].as<float>();
        text.scale = component["scale"].as<float>();
        text.setFont(component["font"].as<std::string>());
    }
    for (auto layer: node["layer"])
        setLayer(layer["name"].as<std::string>(), layer["index"].as<int>());
}