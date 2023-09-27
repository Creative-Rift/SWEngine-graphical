/*
** ShipWreck engine, 2021
** Test.cpp.cc
*/

#include "ScriptTest.hpp"
#include "GameObject.hpp"
#include "EventManager.hpp"
#include "Scene.hpp"

ScriptTest::ScriptTest(sw::GameObject& entity) :
sw::Component(entity)
{
    auto& eventManager = m_gameObject.scene().eventManager;

    eventManager["Start"].subscribe("", this, &ScriptTest::start);
    eventManager["Update"].subscribe("", this, &ScriptTest::update);
}

void ScriptTest::start()
{
    std::cout << "Start" << std::endl;
}

void ScriptTest::update()
{
    std::cout << "Update" << std::endl;
}