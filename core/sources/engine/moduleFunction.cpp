/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * moduleFunction.cpp
 *
 * Description:
 * Engine Module functions implementation
 */

#include "Engine.hpp"

sw::AModule& sw::Engine::getModule()
{
    if (!hasModule())
        throw sw::Error(sw::Log::error112(FUNCTION));
    return (*m_module);
}

void sw::Engine::executeDeleteModule()
{
    m_module.reset();
    m_moduleToDelete = false;
}

void sw::Engine::deleteModule()
{
    if (!hasModule()) {
        sw::Speech::Warning(sw::Log::warning132(FUNCTION));
        return;
    }
    m_moduleToDelete = true;
}