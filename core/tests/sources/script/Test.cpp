/*
** ShipWreck engine, 2021
** Test.cpp.cc
*/

#include "ScriptTest.hpp"

ScriptTest::ScriptTest(sw::Entity& entity) : sw::Component(entity)
{
    auto& eventManager = m_entity.scene().eventManager();

    eventManager["Start"].subscribe(this, &ScriptTest::start);
    eventManager["Update"].subscribe(this, &ScriptTest::update);
}

void ScriptTest::start()
{
    std::cout << "Start" << std::endl;
}

void ScriptTest::update()
{
    std::cout << "Update" << std::endl;
}