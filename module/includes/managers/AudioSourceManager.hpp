/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: TransformManager.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_AUDIOSOURCEMANAGER_HPP
#define SWENGINE_OPENGLMODULE_AUDIOSOURCEMANAGER_HPP

#include "base/AManager.hpp"
#include "../components/AudioSource.hpp"
#include "../OpenGLModule_Config.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT AudioSourceManager : public sw::AManager<AudioSource>
    {
        public:
            using sw::AManager<AudioSource>::AManager;
            ~AudioSourceManager() override = default;

            void onUpdate() override;
    }; // class AudioSourceManager

} // namespace sw

#endif //SWENGINE_OPENGLMODULE_AUDIOSOURCEMANAGER_HPP
