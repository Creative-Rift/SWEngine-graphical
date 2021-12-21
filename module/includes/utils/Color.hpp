/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Colors.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_COLOR_HPP
#define SWENGINE_OPENGLMODULE_COLOR_HPP

#include <cstdint>

namespace sw
{
    class Color {
        public:
            std::uint8_t r; // Red value
            std::uint8_t g; // Green value
            std::uint8_t b; // Blue value
            std::uint8_t a; // Alpha value

            ////////////////////////////////////////////////////////////
            /// @brief Default constructor
            ///
            /// Build default black color (0, 0, 0, 255)
            ///
            ////////////////////////////////////////////////////////////
            constexpr Color();

            ////////////////////////////////////////////////////////////
            /// @brief Construct custome color
            ///
            /// @param red      Value in range [0, 255]
            /// @param green    Value in range [0, 255]
            /// @param blue     Value in range [0, 255]
            /// @param alpha    Value in range [0, 255]
            ///
            ////////////////////////////////////////////////////////////
            constexpr Color(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha = 255);

            static const Color Black;       // Black predefined color
            static const Color White;       // White predefined color
            static const Color Red;         // Red predefined color
            static const Color Green;       // Green predefined color
            static const Color Blue;        // Blue predefined color
            static const Color Yellow;      // Yellow predefined color
            static const Color Magenta;     // Magenta predefined color
            static const Color Cyan;        // Cyan predefined color
            static const Color Transparent; // Transparent (black) predefined color
    }; // class Color

    #include "Color.inl"

} // namespace sw

#endif //SWENGINE_OPENGLMODULE_COLOR_HPP
