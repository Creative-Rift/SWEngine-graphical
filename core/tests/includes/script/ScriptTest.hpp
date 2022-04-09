/*
** ShipWreck engine, 2021
** Test.hpp.h
*/

#ifndef SHIPWRECK_ENGINE_TEST
#define SHIPWRECK_ENGINE_TEST

#include "SW/Component.hpp"

class ScriptTest : public sw::Component
{
public:
    explicit ScriptTest(sw::Entity& entity);
    ~ScriptTest() override = default;
    void start();
    void update();
};


#endif //SHIPWRECK_ENGINE_TEST
