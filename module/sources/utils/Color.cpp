/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Color.cpp
** Description: [CHANGE]
*/

#include "utils/Color.hpp"

sw::Color sw::BlackColor = {0, 0, 0};
sw::Color sw::WhiteColor = {255, 255, 255};
sw::Color sw::RedColor = {255, 0, 0};
sw::Color sw::GreenColor = {0, 255, 0};
sw::Color sw::BlueColor = {0, 0, 255};
sw::Color sw::YellowColor = {255, 255, 0};
sw::Color sw::MagentaColor = {255, 0, 255};
sw::Color sw::CyanColor = {0, 255, 255};
sw::Color sw::TransparentColor = {0, 0, 0, 0};

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