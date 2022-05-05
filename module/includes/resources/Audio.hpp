/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Audio.hpp
** Description: [CHANGE]
*/

#ifndef SHIPWRECK_ENGINE_AUDIO_HPP
#define SHIPWRECK_ENGINE_AUDIO_HPP

#include <string>
#include <vector>

#include "sndfile/sndfile.h"
#include "openal/al.h"

#include "OpenGLModule_Config.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT Audio
    {
        private:
            SNDFILE *m_file;
            SF_INFO m_fileInfo;
            ALsizei m_numberSamples;
            ALsizei m_rate;
            std::vector<ALshort> m_samples;
            ALenum m_format;
            ALuint m_buffer;
            double m_duration;

        public:
            explicit Audio(std::string path);
            ~Audio();

            [[nodiscard]] ALuint getBuffer() const;
            [[nodiscard]] double getDuration() const;
    };
}

#endif //SHIPWRECK_ENGINE_AUDIO_HPP
