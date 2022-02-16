/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Sprite.h
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_TEST_SPRITE_HPP
#define SWENGINE_OPENGLMODULE_TEST_SPRITE_HPP

#include "SW/Component.hpp"
#include "utils/Color.hpp"
#include "utils/VertexArray.hpp"
#include "utils/Shader.hpp"

namespace sw
{
    class Sprite : public sw::Component
    {

        private:
            VertexArray m_vertexArray;
            //sf::Texture m_texture;
            std::string m_textureName;
            Color m_color;
            Shader m_shader;
            //sf::FloatRect m_rect;
            bool m_invertedX;
            bool m_invertedY;

        public:
            //Sprite() = delete;
            //Sprite(Sprite const&) = delete;
            //Sprite(Sprite&&) = delete;
            //Sprite& operator=(Sprite const&) = delete;
            //Sprite& operator=(Sprite&&) = delete;
            ////////////////////////////////////////////////////////////////////////////
            /// \brief Default constructor
            ///
            /// \param engine
            /// \param entity
            ////////////////////////////////////////////////////////////////////////////
            Sprite(sw::Entity& entityRef);

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Default destructor
            ////////////////////////////////////////////////////////////////////////////
            ~Sprite() = default;

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Get the current texture associated with the sprite
            ///
            /// \return reference to the texture
            ////////////////////////////////////////////////////////////////////////////
            //const sf::Texture& texture() const;

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Get the vertex array (this array compose the displayed sprite)
            ///
            /// \return A copy of vertex array
            ////////////////////////////////////////////////////////////////////////////
            [[nodiscard]] const VertexArray& getVertexArray() const;

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Define the displayed texture
            ///
            /// \param texture
            /// \return A reference to the sprite
            ////////////////////////////////////////////////////////////////////////////
            Sprite& setTexture(std::string name);

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Define a rect displayed
            ///
            /// \param rect
            /// \return A reference to the sprite
            ////////////////////////////////////////////////////////////////////////////
            //Sprite& setTextureRect(sf::FloatRect rect);

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Define a color (this color is multiplied with the texture)
            ///
            /// \param color
            /// \return A reference to the sprite
            ////////////////////////////////////////////////////////////////////////////
            Sprite& setColor(const sw::Color &color);

            void invertX(bool invert);
            void invertY(bool invert);

            bool isInvertX() const;
            bool isInvertY() const;

            void updateInvert();

            friend void defineRect(Sprite& sp);

            [[nodiscard]] const Shader& getShader() const noexcept;
            [[nodiscard]] std::string type() const override { return("Sprite"); };

    }; // class Sprite

    void defineRect(Sprite& sp);

} // namespace sw

#endif //SWENGINE_OPENGLMODULE_TEST_SPRITE_HPP