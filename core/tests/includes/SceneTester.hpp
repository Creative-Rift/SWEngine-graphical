/*
** Society: Rift...
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: SceneTester.h
** Description: [CHANGE]
*/

#ifndef __UNITESTS_SCENETESTER_HPP__
#define __UNITESTS_SCENETESTER_HPP__

#include "testHeader.hpp"

class CptManagerThrow
        :   public sw::AManager<sw::Component>
{
    public:
        using sw::AManager<sw::Component>::AManager;
        ~CptManagerThrow() = default;

        void onUpdate() override
        {
            throw (sw::Error("TestCptManagerThrow", "Code"));
        }
        std::string type() const override { return ("CptManagerThrow"); }
};

class TestThrowScene
        :   public sw::AScene
{
    public:
        using sw::AScene::AScene;
        ~TestThrowScene() = default;
        bool m_init = false;
        bool m_update = false;
        bool m_term = false;
        bool m_manager = false;

        void onLoad() override
        {
            if (m_init) throw (sw::Error("TestThrowScene", "Code"));
            if (m_manager) createManager<CptManagerThrow>("CptManagerThrow");
        }
        void onUpdate() override
        {
            if (m_update) throw (sw::Error("TestThrowScene", "Code"));
        }
        void onUnload() override
        {
            if (m_term) throw (sw::Error("TestThrowScene", "Code"));
        }
        std::string type() const override { return ("TestThrowScene"); }
};

class SceneTester
    :   public ComponentTester
{

};

#endif // __UNITESTS_SCENETESTER_HPP__
