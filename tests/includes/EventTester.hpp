/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** EventTester.hpp
*/

#ifndef __UNITESTS_EVENTTESTER_HPP__
#define __UNITESTS_EVENTTESTER_HPP__

#include <gtest/gtest.h>
#include "BaseEngineTest.hpp"
#include "OpenGLModule.hpp"
#include "Scene.hpp"
#include "AManager.hpp"
#include "Component.hpp"
#include "Engine_tests.hpp"

class Script : public sw::Component
{
    public:
        using sw::Component::Component;
        void helloWorld()
        {
            std::cout << "Hello World !" << std::endl;
        }
};

class EventTester : public BaseEngineTest
{
    public:
        virtual void SetUp() // TODO check how to tests event (maybe not now)
        {
            //scene.createEntity("Entity");
            //fact.createComponent<Script>("Entity");
            //sw::Engine::initialize();
        }

        virtual void TearDown()
        {
            //sw::Engine::deleteScene("SceneTest");
            //sw::Engine::terminate();
        }
};

#endif // __UNITESTS_EVENTTESTER_HPP__