/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2023
** Author: Guillaume S.
** File name: Entity.cpp
** Description: [CHANGE]
*/

#ifndef SHIPWRECK_ENGINE_TEXTINPUT_HPP
#define SHIPWRECK_ENGINE_TEXTINPUT_HPP

#include <string>
#include "components/base/Component.hpp"
#include "utils/Reference.hpp"
#include "../Text.hpp"
#include "utils/Vector2.hpp"

namespace sw
{
    class TextInputManager;

    class SW_GRAPH_MODULE_EXPORT TextInput : public Component
    {
        protected:
            bool m_selected;
            std::wstring m_value;

        public:
            Vector2f m_textPos;
            Reference<sw::Text> m_text;

            explicit TextInput(sw::GameObject &gameObject, std::wstring defaultValue = std::wstring(L"Hello World"));
            void start();
            [[nodiscard]] bool isSelected() const;
            [[nodiscard]] const std::wstring &getValue() const;

            friend TextInputManager;

    }; // class TextInput

} // sw

#endif // SHIPWRECK_ENGINE_TEXTINPUT_HPP
