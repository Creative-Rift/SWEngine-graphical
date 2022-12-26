/*
** Society: Rift...
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Engine_tests.hpp
** Description: [CHANGE]
*/

#ifndef __UNITESTS_ENGINE_TESTS_HPP__
#define __UNITESTS_ENGINE_TESTS_HPP__

#include <gtest/gtest.h>
#include "BaseEngineTest.hpp"
#include "OpenGLModule.hpp"
#include "utils/Speech.hpp"

class EngineTestScene
{
    public:
        ~EngineTestScene() {}

        void onLoad() {}
        std::string name() {return ("ye");}
};

class EngineTester : public BaseEngineTest
{
    protected:
        virtual void SetUp() override
        {
            sw::Speech::displayed = false;
            baseSetUp();
        }

        virtual void TearDown() override
        {
            sw::Speech::displayed = true;
            baseTearDown();
        }
};

#endif // __UNITESTS_ENGINE_TESTS_HPP__
