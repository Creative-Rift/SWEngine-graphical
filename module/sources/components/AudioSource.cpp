/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: AudioSource.cpp
** Description: [CHANGE]
*/

#include "AudioSource.hpp"
#include "OpenResources.hpp"

sw::AudioSource::AudioSource(sw::GameObject &gameObject) :
sw::Component(gameObject),
m_source(-1)
{
    alGenSources(1, &m_source);
}

sw::AudioSource::~AudioSource() noexcept
{
    alSourcei(m_source, AL_BUFFER, 0);
    alDeleteSources(1, &m_source);
}

sw::AudioSource &sw::AudioSource::setAudio(std::string audio)
{
    alSourcei(m_source, AL_BUFFER, sw::OpenResources::m_naudio[audio]->getBuffer());
    return (*this);
}

sw::AudioSource &sw::AudioSource::play()
{
    alSourcePlay(m_source);
    return (*this);
}

sw::AudioSource &sw::AudioSource::pause()
{
    alSourcePause(m_source);
    return (*this);
}

sw::AudioSource &sw::AudioSource::stop()
{
    alSourceStop(m_source);
    return (*this);
}

sw::AudioSource &sw::AudioSource::setVolume(float volume)
{
    alSourcef(m_source, AL_GAIN, volume);
    return (*this);
}

sw::AudioSource &sw::AudioSource::setPitch(float pitch)
{
    alSourcef(m_source, AL_PITCH, pitch);
    return (*this);
}