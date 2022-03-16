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

#include "components/Animator.hpp"

namespace sw
{
    class AnimatorManager : public sw::AManager<Animator>
    {
        private:
            void animLine(Animator &animator, double &current_time);
            void animSprite(Animator &animator, double &current_time);
        public:
            using sw::AManager<Animator>::AManager;
            ~AnimatorManager() override = default;

            void onUpdate() override;
    }; // class AnimatorManager
} // namespace sw

#endif //SWENGINE_OPENGLMODULE_ANIMATORMANAGER_HPP