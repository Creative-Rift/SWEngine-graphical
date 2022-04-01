/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: AnimatorManager.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_ANIMATORMANAGER_HPP
#define SWENGINE_OPENGLMODULE_ANIMATORMANAGER_HPP

#include "SW/Manager.hpp"

#include "OpenGLModule_Config.hpp"
#include "components/Animator.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT AnimatorManager : public sw::AManager<Animator>
    {
        private:
            static void animLine(Animator &animator, double &current_time);
            static void animSprite(Animator &animator, double &current_time);
        public:
            using sw::AManager<Animator>::AManager;
            ~AnimatorManager() override = default;

            void onUpdate() override;
    }; // class AnimatorManager
} // namespace sw

#endif //SWENGINE_OPENGLMODULE_ANIMATORMANAGER_HPP
