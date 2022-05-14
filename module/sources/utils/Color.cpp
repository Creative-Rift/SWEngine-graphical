/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Color.cpp
** Description: [CHANGE]
*/

#include "utils/Color.hpp"

YAML::Node sw::Color::save() const
{
    YAML::Node node;

    node["r"] = r;
    node["g"] = g;
    node["b"] = b;
    node["a"] = a;

    return node;
}

void sw::Color::load(YAML::Node node)
{
    r = node["r"].as<float>();
    g = node["g"].as<float>();
    b = node["b"].as<float>();
    a = node["a"].as<float>();
}