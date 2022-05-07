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
    class AudioSourceManager;

    class SW_GRAPH_MODULE_EXPORT AudioSource : public sw::Component
    {
        private:
            ALuint m_source;
            bool m_loop;
            float m_currentSample;
            float m_startPoint;
            float m_startLoopPoint;
            float m_endPoint;
            float m_endLoopPoint;
            bool m_randomized;
            int m_maxOccurence;
            std::vector<std::string> m_audios;
            std::string m_last;
            int m_lastOccurence;

            void defineBuffer(std::string name);
            std::string randomHandler();

        public:
            explicit AudioSource(sw::GameObject& entity);
            ~AudioSource() override;

            AudioSource& addAudio(std::string audio);
            AudioSource& play();
            AudioSource& pause();
            AudioSource& stop();
            AudioSource& setVolume(float volume);
            AudioSource& setPitch(float pitch);
            AudioSource& setLoop(bool loop);
            AudioSource& setStartPoint(float second);
            AudioSource& setStartLoopPoint(float second);
            AudioSource& setEndPoint(float second);
            AudioSource& setEndLoopPoint(float second);
            AudioSource& setRandomized(bool random);
            AudioSource& setMaxOccurence(int occurence);

            friend AudioSourceManager;
    };
}

#endif //SHIPWRECK_ENGINE_AUDIOSOURCE_HPP
