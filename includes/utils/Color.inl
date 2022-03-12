/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Color.inl
** Description: [CHANGE]
*/

constexpr sw::Color::Color() :
r(0),
g(0),
b(0),
a(255)
{}

constexpr sw::Color::Color(float red, float green, float blue, float alpha) :
r(red),
g(green),
b(blue),
a(alpha)
{}
