/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Sprite.h
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_SPRITE_HPP
#define SWENGINE_OPENGLMODULE_SPRITE_HPP

#include "base/Component.hpp"
#include "utils/Rect.hpp"

#include "yaml-cpp/yaml.h"
#include "yaml-cpp/node/detail/node.h"

#include "utils/Color.hpp"
#include "utils/VertexArray.hpp"
#include "utils/Shader.hpp"
#include "resources/OpenResources.hpp"
#include "components/Material.hpp"

#include "OpenGLModule_Config.hpp"

namespace sw
{

    class SpriteManager;

    /// \brief A Sprite is a component who display any image you want. \n
    /// Give a texture and modify the parameters to get the desired result. \n
    /// Mandatory if you use an Animator.
    class SW_GRAPH_MODULE_EXPORT Sprite : public sw::Component
    {
        protected:
            VertexArray m_vertexArray;
            Material m_material;
            Color m_color;
            sw::FloatRect m_rect;
            bool m_invertedX;
            bool m_invertedY;

            YAML::Node save() const;

        public:
            /// \brief All default constructor are deleted because a component must
            /// be attached to an Entity
            Sprite() = delete;
            Sprite(Sprite const&) = delete;
            Sprite(Sprite&&) = delete;
            Sprite& operator=(Sprite const&) = delete;
            Sprite& operator=(Sprite&&) = delete;


            /// \brief Default constructor
            ///
            /// \param entityRef A reference to the entity that own the component
            explicit Sprite(sw::GameObject& gameObject);


            /// \brief Default destructor
            ~Sprite() override = default;

            /// \brief Get the current texture associated to the sprite
            ///
            /// \return Reference to the texture
            [[nodiscard]]std::shared_ptr<Texture> texture() const;

            /// \brief Define the displayed texture
            ///
            /// \param texture Name of the texture
            ///
            /// \return A reference to the sprite
            Sprite& setTexture(std::string& name);

            /// \brief Define a rect displayed applied on the texture
            ///
            /// \param rect Dimension of the rect
            ///
            /// \return A reference to the sprite
            Sprite& setTextureRect(sw::FloatRect& rect);

            /// \brief Define a color (this color is multiplied with the texture pixels)
            ///
            /// \param color
            ///
            /// \return A reference to the sprite
            Sprite& setColor(const sw::Color &color);

            /// \brief Flip the texture on X axis
            ///
            /// \param invert Boolean that define if the texture is flipped (true) or not (false)
            /// \return Reference to the Sprite
            Sprite& flipOnX(bool invert);

            /// \brief Flip the texture on Y axis
            ///
            /// \param invert Boolean that define if the texture is flipped (true) or not (false)
            /// \return Reference to the Sprite
            Sprite& flipOnY(bool invert);

            /// \brief Get the value if the Sprite texture is flipped on X axis
            ///
            /// \return Boolean with the value true if he is flipped false otherwise
            [[nodiscard]] bool isFlippedX() const;

            /// \brief Get the value if the Sprite texture is flipped on Y axis
            ///
            /// \return Boolean with the value true if he is flipped false otherwise
            [[nodiscard]] bool isFlippedY() const;

            /// \brief Get the shader associated
            ///
            /// \return A reference to the Shader
            [[nodiscard]] const std::shared_ptr<Shader> getShader() const noexcept;

            /// \brief Get the shader associated
            ///
            /// \return A reference to the Shader
            [[nodiscard]] Material& getMaterial() noexcept;


            friend SpriteManager;

    }; // class Sprite


} // namespace sw

#endif //SWENGINE_OPENGLMODULE_SPRITE_HPP
