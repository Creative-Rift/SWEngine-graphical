/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: AudioSource.cpp
** Description: [CHANGE]
*/

#include "AudioSource.hpp"
#include "OpenResources.hpp"
#include "GameObject.hpp"

sw::AudioSource::AudioSource(sw::GameObject &gameObject) :
sw::Component(gameObject),
m_source(-1),
m_loop(false),
m_currentSample(0.0f),
m_startPoint(0.0f),
m_startLoopPoint(-1),
m_endLoopPoint(-1),
m_endPoint(-1)
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
    auto audioFile = sw::OpenResources::m_naudio[audio];
    alSourcei(m_source, AL_BUFFER, audioFile->getBuffer());
    m_endPoint = audioFile->getDuration();
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
    setStartLoopPoint(m_startPoint);
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

sw::AudioSource &sw::AudioSource::setLoop(bool loop)
{
    m_loop = loop;
    alSourcei(m_source, AL_LOOPING, m_loop ? AL_TRUE : AL_FALSE);
    return (*this);
}

sw::AudioSource &sw::AudioSource::setStartPoint(float second)
{
    alSourcef(m_source, AL_SEC_OFFSET, second);
    return (*this);
}

sw::AudioSource &sw::AudioSource::setStartLoopPoint(float second)
{
    m_startLoopPoint = second;
    return (*this);
}

sw::AudioSource &sw::AudioSource::setEndPoint(float second)
{
    m_endPoint = second;
    return (*this);
}

sw::AudioSource &sw::AudioSource::setEndLoopPoint(float second)
{
    m_endLoopPoint = second;
    return (*this);
}