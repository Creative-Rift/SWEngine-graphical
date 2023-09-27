/*
** Society: Rift...
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: SceneTester.h
** Description: [CHANGE]
*/

#ifndef __UNITESTS_SCENETESTER_HPP__
#define __UNITESTS_SCENETESTER_HPP__

#include "BaseEngineTest.hpp"

class CptManagerThrow : public sw::AManager<sw::Component>
{
    public:
        using sw::AManager<sw::Component>::AManager;
        ~CptManagerThrow() = default;

        void onUpdate() override
        {
            throw (sw::Error("TestCptManagerThrow", "Code"));
        }
};

class TestThrowScene
{
    public:
        ~TestThrowScene() = default;
        bool m_init = false;
        bool m_update = false;
        bool m_term = false;
        bool m_manager = false;

        void onLoad(sw::EventInfo& info)
        {
            auto& scene = info.getInfo<sw::SceneLoadEvent>().scene;

            if (scene.name != "Engine")
                return;

            if (m_init) throw (sw::Error("TestThrowScene", "Code"));
            if (m_manager) scene.createManager<CptManagerThrow>("CptManagerThrow");
        }
        void onUpdate() // TODO subscribe to the Update of the game
        {
            if (m_update) throw (sw::Error("TestThrowScene", "Code"));
        }
        void onUnload() // TODO check if we have event to catch for unload
        {
            if (m_term) throw (sw::Error("TestThrowScene", "Code"));
        }
};

class SceneTester : public BaseEngineTest
{

};

#endif // __UNITESTS_SCENETESTER_HPP__
