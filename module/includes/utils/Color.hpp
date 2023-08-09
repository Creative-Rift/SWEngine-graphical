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

    extern SW_GRAPH_MODULE_EXPORT Color BlackColor;         // Black predefined color
    extern SW_GRAPH_MODULE_EXPORT Color WhiteColor;         // White predefined color
    extern SW_GRAPH_MODULE_EXPORT Color RedColor;           // Red predefined color
    extern SW_GRAPH_MODULE_EXPORT Color GreenColor;         // Green predefined color
    extern SW_GRAPH_MODULE_EXPORT Color BlueColor;          // Blue predefined color
    extern SW_GRAPH_MODULE_EXPORT Color YellowColor;        // Yellow predefined color
    extern SW_GRAPH_MODULE_EXPORT Color MagentaColor;       // Magenta predefined color
    extern SW_GRAPH_MODULE_EXPORT Color CyanColor;          // Cyan predefined color
    extern SW_GRAPH_MODULE_EXPORT Color TransparentColor;   // Transparent (black) predefined color



} // namespace sw

#endif //SWENGINE_OPENGLMODULE_COLOR_HPP
