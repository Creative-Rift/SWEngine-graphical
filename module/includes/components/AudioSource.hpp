/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: AudioSource.hpp
** Description: [CHANGE]
*/

#ifndef SHIPWRECK_ENGINE_AUDIOSOURCE_HPP
#define SHIPWRECK_ENGINE_AUDIOSOURCE_HPP

#include "components/base/Component.hpp"
#include "../OpenGLModule_Config.hpp"

#include "../resources/Audio.hpp"

#include "openal/al.h"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT AudioSource : public sw::Component
    {
        private:
            ALuint m_source;
        public:
            explicit AudioSource(sw::GameObject& entity);
            ~AudioSource() override;

            AudioSource& setAudio(std::string audio);
            AudioSource& play();
            AudioSource& pause();
            AudioSource& stop();
            AudioSource& setVolume(float volume);
            AudioSource& setPitch(float pitch);
    };
}

#endif //SHIPWRECK_ENGINE_AUDIOSOURCE_HPP
