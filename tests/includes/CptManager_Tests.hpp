/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: CptManager.hpp
** Description: [CHANGE]
*/

#ifndef __UNITESTS_CPTMANAGER_HPP__
#define __UNITESTS_CPTMANAGER_HPP__

#include "BaseEngineTest.hpp"

class TestCptManagerThrow : public sw::AManager<sw::Component>
{
    public:
        using sw::AManager<sw::Component>::AManager;
        ~TestCptManagerThrow() = default;
        bool m_update = false;

        void onUpdate() override
        {
            if (m_update)
                throw (sw::Error("onUpdate", "Code"));
        }
};

class CptManagerTester : public BaseEngineTest
{

};

#endif // __UNITESTS_CPTMANAGER_HPP__
