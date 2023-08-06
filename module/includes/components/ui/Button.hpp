/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2023
** Author: Guillaume S.
** File name: Entity.cpp
** Description: [CHANGE]
*/


#ifndef SHIPWRECK_ENGINE_BUTTON_HPP
#define SHIPWRECK_ENGINE_BUTTON_HPP

#include "components/base/Component.hpp"
#include "components/Sprite.hpp"
#include "components/Text.hpp"
#include "components/AudioSource.hpp"
#include "utils/Vector2.hpp"
#include "utils/Vector3.hpp"
#include "utils/Reference.hpp"

namespace sw {

    class ButtonManager;

    class SW_GRAPH_MODULE_EXPORT Button : public Component
    {
        public:
            explicit Button(sw::GameObject &gameObject);
            std::string m_textureName;
            std::string m_buttonTitle;
            sw::Vector2f m_scale;
            sw::Vector3f m_position;
            sw::Vector3f m_txtPosition;
            void (*m_callback)(Button *);
            AudioSource &getAudio();
            Text &getText();

        protected:
            sw::Reference<sw::Sprite> m_sprite;
            sw::Reference<sw::Text> m_text;
            sw::Reference<sw::AudioSource> m_audio;
            bool m_hover;
            void start();
            void update();

            friend ButtonManager;
    }; // class Button

} // sw

#endif // SHIPWRECK_ENGINE_BUTTON_HPP
