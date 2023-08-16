//
// Created by guill on 15/08/2023.
//

#ifndef SHIPWRECK_ENGINE_CHECKBOX_HPP
#define SHIPWRECK_ENGINE_CHECKBOX_HPP

#include "components/base/Component.hpp"
#include "components/Components.hpp"
#include "utils/Reference.hpp"
#include "utils/Rect.hpp"

namespace sw
{

    class CheckBoxManager;

    class SW_GRAPH_MODULE_EXPORT CheckBox : public Component
    {
        public:
            FloatRect m_hitBox;
            Vector2f m_scale;
            explicit CheckBox(GameObject& gameObject, std::string spriteOn, std::string spriteOff, bool defaultValue = false);
            [[nodiscard]] bool getValue() const;

        protected:
            Reference<Sprite> m_sprite;
            bool m_value;
            bool m_hover;
            std::string m_spriteOff;
            std::string m_spriteOn;

            void start();

            friend CheckBoxManager;
    };

} // sw

#endif //SHIPWRECK_ENGINE_CHECKBOX_HPP
