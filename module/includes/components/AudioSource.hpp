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
#include "yaml-cpp/yaml.h"

#include "../resources/Audio.hpp"

#include "openal/al.h"

namespace sw
{

    class AudioSourceManager;

    class SW_GRAPH_MODULE_EXPORT AudioSource : public sw::Component
    {
        private:
            ALuint m_source;
            std::string m_audioFile;
            float m_volume;
            float m_pitch;
            bool m_playOnStart;
            YAML::Node save() const;

            void playOnStart();
        public:
            explicit AudioSource(sw::GameObject& entity);
            ~AudioSource() override;

            AudioSource& setAudio(std::string audio);
            AudioSource& play();
            AudioSource& pause();
            AudioSource& stop();
            AudioSource& setVolume(float volume);
            AudioSource& setPitch(float pitch);
            ////////////////////////////////////////////////////////////////////////////
            /// \brief Define if the Audio will play on start
            ///
            /// \param value boolean
            /// \return reference to your Audio
            ////////////////////////////////////////////////////////////////////////////
            AudioSource& setPlayOnStart(bool value);

            ////////////////////////////////////////////////////////////////////////////
            /// \brief Get if the animation will play on start
            ///
            /// \return bool
            ////////////////////////////////////////////////////////////////////////////
            [[nodiscard]]const bool& getPlayOnStart();

            friend AudioSourceManager;
    };
}

#endif //SHIPWRECK_ENGINE_AUDIOSOURCE_HPP
