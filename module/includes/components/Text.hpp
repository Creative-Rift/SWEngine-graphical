#ifndef SWENGINE_OPENGLMODULE_TEXT_TXT_HPP
#define SWENGINE_OPENGLMODULE_TEXT_TXT_HPP

#include "base/Component.hpp"
#include "yaml-cpp/yaml.h"

#include "utils/Color.hpp"
#include "resources/Font.hpp"
#include "utils/Shader.hpp"

#include "OpenGLModule_Config.hpp"

#include <string>
#include <memory>

namespace sw
{

    class TextManager;

    class SW_GRAPH_MODULE_EXPORT Text : public sw::Component
    {
        private:
            std::string m_text;
            std::string m_fontName;
            unsigned int m_size;
            std::shared_ptr<Font> m_font;
            sw::Color m_color;
            std::shared_ptr<Shader> m_shader;
            std::pair<float, float> m_pos;
            float m_scale;
            //float m_lineSpacing;
            //unsigned int m_nbrDisplayedChar;

            YAML::Node save() const;
        public:
        /*
            enum Style {
                Regular = 0,
                Bold = 1 << 0,
                Italic = 1 << 1,
                Underlined = 1 << 2,
                StrikeThrough = 1 << 3
            } m_style;*/

            Text() = delete;
            Text(Text const&) = delete;
            Text(Text&&) = delete;
            Text& operator=(Text const&) = delete;
            Text& operator=(Text&&) = delete;
            explicit Text(sw::GameObject& gameObject);

            Text& setText(std::string text);
            //Text& setFontSize(unsigned int size);
            Text& setFont(std::string name);
            Text& setColor(sw::Color color);
            Text &setPosition(float xpos, float ypos);
            Text &setSize(float scale);

            [[nodiscard]] const std::shared_ptr<Shader> getShader() const noexcept;
            [[nodiscard]] const Color& getColor() const noexcept;
            [[nodiscard]] const std::string& getText() const noexcept;
            [[nodiscard]] const std::shared_ptr<sw::Font>& getFont() const noexcept;
            [[nodiscard]] const std::pair<float, float>& getPos() const noexcept;
            [[nodiscard]] const float& getScale() const noexcept;
            //Text& setNumberChar(unsigned int nbr);

            friend TextManager;

    }; // class Text

} // namespace sw

#endif //SWENGINE_OPENGLMODULE_TEXT_TXT_HPP