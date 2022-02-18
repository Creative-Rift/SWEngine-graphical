/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Main.cpp
** Description: [CHANGE]
*/

#include "managers/TransformManager.hpp"

#include "../../../includes/scenes/Main.hpp"

void Main::onLoad()
{
    createManager<sw::TransformManager>("TransformManager");
}

void Main::onUpdate()
{}

void Main::onUnload()
{}