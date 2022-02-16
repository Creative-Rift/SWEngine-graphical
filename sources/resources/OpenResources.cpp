/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Resources.cpp
** Description: [CHANGE]
*/

#include "resources/OpenResources.hpp"

sw::OpenResources::~OpenResources()
{
    while(!m_tx.empty())
    {
        m_tx.pop();
    }
}

void sw::OpenResources::loadResources()
{}

void sw::OpenResources::loadResourcesFile(const std::string &path)
{}

void sw::OpenResources::unloadResources()
{}
