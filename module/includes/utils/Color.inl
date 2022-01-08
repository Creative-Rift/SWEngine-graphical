/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Color.inl
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_COLOR_INL
#define SWENGINE_OPENGLMODULE_COLOR_INL

constexpr sw::Color::Color() :
r(0),
g(0),
b(0),
a(255)
{}

constexpr sw::Color::Color(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha) :
r(red),
g(green),
b(blue),
a(alpha)
{}

#endif //SWENGINE_OPENGLMODULE_COLOR_INL
