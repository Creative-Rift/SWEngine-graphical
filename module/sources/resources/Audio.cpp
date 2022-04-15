/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Audio.cpp
** Description: [CHANGE]
*/

#include <iostream>

#include "Audio.hpp"
#include "includes/error/Error.hpp"

sw::Audio::Audio(std::string path) :
m_file(nullptr),
m_fileInfo()
{
    m_file = sf_open(path.c_str(), SFM_READ, &m_fileInfo);
    if (!m_file)
        throw sw::Error("Cannot open file: " + path, "");
    m_numberSamples = (ALsizei)(m_fileInfo.channels * m_fileInfo.frames);
    m_rate = (ALsizei)m_fileInfo.samplerate;
    m_samples.resize(m_numberSamples);
    sf_read_short(m_file, &m_samples[0], m_numberSamples);
    sf_close(m_file);

    switch (m_fileInfo.channels) {
        case 1: m_format = AL_FORMAT_MONO16; break;
        case 2: m_format = AL_FORMAT_STEREO16; break;
        default: m_format = -1;
    }

    alGenBuffers(1, &m_buffer);
    alBufferData(m_buffer, m_format, &m_samples[0], m_numberSamples * sizeof(ALushort), m_rate);
    if (alGetError() != AL_NO_ERROR)
        std::cerr << "Audio not loaded" << std::endl;
}

sw::Audio::~Audio() noexcept
{
    alDeleteBuffers(1, &m_buffer);

}

ALuint sw::Audio::getBuffer() const
{
    return (m_buffer);
}