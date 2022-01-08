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

    }; // class Color

    #include "Color.inl"

    constexpr Color BlackColor(0, 0, 0);             // Black predefined color
    constexpr Color WhiteColor(255, 255, 255);       // White predefined color
    constexpr Color RedColor(255, 0, 0);             // Red predefined color
    constexpr Color GreenColor(0, 255, 0);           // Green predefined color
    constexpr Color BlueColor(0, 0, 255);            // Blue predefined color
    constexpr Color YellowColor(255, 255, 0);        // Yellow predefined color
    constexpr Color MagentaColor(255, 0, 255);       // Magenta predefined color
    constexpr Color CyanColor(0, 255, 255);          // Cyan predefined color
    constexpr Color TransparentColor(0, 0, 0, 0);    // Transparent (black) predefined color



} // namespace sw

#endif //SWENGINE_OPENGLMODULE_COLOR_HPP
