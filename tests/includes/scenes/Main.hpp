    /*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Main.h
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_TEST_MAIN_HPP
#define SWENGINE_OPENGLMODULE_TEST_MAIN_HPP

#include "SW/Scene.hpp"

class Main : public sw::AScene{
    public:
        using sw::AScene::AScene;

        void onLoad() override;
        void onUpdate() override;
        void onUnload() override;
        std::string type() const override { return ("Main"); }

};

#endif //SWENGINE_OPENGLMODULE_TEST_MAIN_HPP
