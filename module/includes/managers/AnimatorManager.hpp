/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: AnimatorManager.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_ANIMATORMANAGER_HPP
#define SWENGINE_OPENGLMODULE_ANIMATORMANAGER_HPP

#include "base/AManager.hpp"

#include "OpenGLModule_Config.hpp"
#include "components/Animator.hpp"

namespace sw
{
    /// \brief The Animator Manager update all Animator, there is some rules
    /// defined for each Animation Type
    ///
    class SW_GRAPH_MODULE_EXPORT AnimatorManager : public sw::AManager<Animator>
    {
        private:

            /// \brief Update Animation following rules defined for the Type
            ///         sw::Animator::ANIM_LINE
            ///
            /// \param animator Reference to the animator
            /// \param current_time get total time
            static void animLine(Animator &animator, double &current_time);
            static void animSprite(Animator &animator, double &current_time);
        public:
            /// \brief Default constructor of the AManager class
            using sw::AManager<Animator>::AManager;

            /// \brief Default destructor
            ~AnimatorManager() override = default;

            /// \brief This function is called one time per frame and update all component \n
            /// stored according their data
            void onUpdate() override;
    }; // class AnimatorManager
} // namespace sw

#endif //SWENGINE_OPENGLMODULE_ANIMATORMANAGER_HPP
