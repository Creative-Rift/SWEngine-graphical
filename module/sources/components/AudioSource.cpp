/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: AudioSource.cpp
** Description: [CHANGE]
*/

#include "AudioSource.hpp"
#include "OpenResources.hpp"
#include "Speech.hpp"
#include "GameObject.hpp"

sw::AudioSource::AudioSource(sw::GameObject &gameObject) :
sw::Component(gameObject),
m_source(-1),
m_audioFile(),
m_volume(),
m_pitch(),
m_playOnStart(true)
{
    alGenSources(1, &m_source);
    gameObject.scene().eventManager["Start"].subscribe(this, &AudioSource::playOnStart);
}

void sw::AudioSource::playOnStart()
{
    if (m_playOnStart)
        play();
}

sw::AudioSource::~AudioSource() noexcept
{
    alSourcei(m_source, AL_BUFFER, 0);
    alDeleteSources(1, &m_source);
}

sw::AudioSource &sw::AudioSource::setAudio(std::string audio)
{
    alSourcei(m_source, AL_BUFFER, sw::OpenResources::m_naudio[audio]->getBuffer());
    m_audioFile = audio;
    alGetSourcef(m_source, AL_GAIN, &m_volume);
    alGetSourcef(m_source, AL_PITCH, &m_pitch);
    return (*this);
}

sw::AudioSource &sw::AudioSource::play()
{
    if (m_source == -1) {
        sw::Speech::Warning("No sound defined cannot play");
        return (*this);
    }
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
    m_volume = volume;
    alSourcef(m_source, AL_GAIN, volume);
    return (*this);
}

sw::AudioSource &sw::AudioSource::setPitch(float pitch)
{
    m_pitch = pitch;
    alSourcef(m_source, AL_PITCH, pitch);
    return (*this);
}

YAML::Node sw::AudioSource::save() const
{
    YAML::Node node;

    node["entity_name"] = name();
    node["audioFile"] = m_audioFile;
    node["volume"] = m_volume;
    node["pitch"] = m_pitch;
    node["playOnStart"] = m_playOnStart;

    return (node);
}

const bool &sw::AudioSource::getPlayOnStart()
{
    return (m_playOnStart);
}

sw::AudioSource& sw::AudioSource::setPlayOnStart(bool value)
{
    m_playOnStart = value;
    return (*this);
}