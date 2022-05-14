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
#include "OpenGLModule_Config.hpp"
#include "yaml-cpp/yaml.h"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT Color {
        public:
            float r; // Red value
            float g; // Green value
            float b; // Blue value
            float a; // Alpha value

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
            constexpr Color(float red, float green, float blue, float alpha = 255);

            YAML::Node save() const;
            void load(YAML::Node node);

    }; // class Color

    #include "Color.inl"

    constexpr SW_GRAPH_MODULE_EXPORT Color BlackColor(0, 0, 0);             // Black predefined color
    constexpr SW_GRAPH_MODULE_EXPORT Color WhiteColor(255, 255, 255);       // White predefined color
    constexpr SW_GRAPH_MODULE_EXPORT Color RedColor(255, 0, 0);             // Red predefined color
    constexpr SW_GRAPH_MODULE_EXPORT Color GreenColor(0, 255, 0);           // Green predefined color
    constexpr SW_GRAPH_MODULE_EXPORT Color BlueColor(0, 0, 255);            // Blue predefined color
    constexpr SW_GRAPH_MODULE_EXPORT Color YellowColor(255, 255, 0);        // Yellow predefined color
    constexpr SW_GRAPH_MODULE_EXPORT Color MagentaColor(255, 0, 255);       // Magenta predefined color
    constexpr SW_GRAPH_MODULE_EXPORT Color CyanColor(0, 255, 255);          // Cyan predefined color
    constexpr SW_GRAPH_MODULE_EXPORT Color TransparentColor(0, 0, 0, 0);    // Transparent (black) predefined color



} // namespace sw

#endif //SWENGINE_OPENGLMODULE_COLOR_HPP
