/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: AudioSource.cpp
** Description: [CHANGE]
*/

#include "AudioSource.hpp"

#include <utility>
#include "OpenResources.hpp"
#include "OpenGLModule.hpp"
#include "scenes_manager/SceneManager.hpp"
#include "Speech.hpp"
#include "GameObject.hpp"

sw::AudioSource::AudioSource(sw::GameObject &gameObject) :
sw::Component(gameObject),
m_source(-1),
m_loop(false),
m_currentSample(0.0f),
m_startPoint(0.0f),
m_startLoopPoint(-1),
m_endLoopPoint(-1),
m_endPoint(-1),
m_randomized(false),
m_maxOccurence(-1),
m_audios(),
m_last(),
m_lastOccurence(0),
m_volume(),
m_pitch(),
m_playOnStart(true)
{
    alGenSources(1, &m_source);
    //gameObject.scene().eventManager["Start"].subscribe(m_gameObject.name(), this, &AudioSource::playOnStart);
}

sw::AudioSource::~AudioSource() noexcept
{
    alSourcei(m_source, AL_BUFFER, 0);
    alDeleteSources(1, &m_source);
    //m_gameObject.scene().eventManager["Start"].unsubscribe(m_gameObject.name());
}

void sw::AudioSource::playOnStart()
{
    if (m_playOnStart)
        play();
}

void sw::AudioSource::defineBuffer(std::string name)
{
    auto buffer = sw::OpenResources::m_naudio[name];
    alSourcei(m_source, AL_BUFFER, buffer->getBuffer());
    m_endPoint = buffer->getDuration();
    ALenum error = alGetError();
    if ( error != AL_NO_ERROR)
        std::cerr << error << std::endl;
}

std::string sw::AudioSource::randomHandler()
{
    int index;
    std::string audioName;

    if (m_audios.size() < 2)
        return m_audios[0];
    do {
        index = std::rand() % (m_audios.size() - 1);
        audioName = m_audios[index];
    } while (m_last == audioName && m_lastOccurence == m_maxOccurence);
    if (m_last == audioName)
        m_lastOccurence++;
    else {
        m_lastOccurence = 1;
        m_last = audioName;
    }
    return audioName;
}

sw::AudioSource &sw::AudioSource::addAudio(std::string audio)
{
    m_audios.emplace_back(audio);
    if (m_audios.size() == 1)
        defineBuffer(m_audios[0]);
    return (*this);
}

sw::AudioSource &sw::AudioSource::play()
{
    stop();
    if (m_randomized)
        defineBuffer(randomHandler());
    alSourcePlay(m_source);
    return (*this);
}

sw::AudioSource &sw::AudioSource::play(int index)
{
    stop();
    defineBuffer(m_audios[index]);
    if (m_randomized)
        defineBuffer(randomHandler());
    alSourcePlay(m_source);
    return (*this);
}

sw::AudioSource &sw::AudioSource::play(std::string name)
{
    stop();
    defineBuffer(std::move(name));
    if (m_randomized)
        defineBuffer(randomHandler());
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

sw::AudioSource &sw::AudioSource::setRandomized(bool random)
{
    m_randomized = random;
    if (!m_randomized)
        defineBuffer(m_audios[0]);
    return (*this);
}

sw::AudioSource &sw::AudioSource::setMaxOccurrence(int occurrence)
{
    m_maxOccurence = occurrence;
    return (*this);
}

YAML::Node sw::AudioSource::save() const
{
    YAML::Node node;

    node["entity_name"] = name();
    node["volume"] = m_volume;
    node["pitch"] = m_pitch;
    node["playOnStart"] = m_playOnStart;

    return (node);
}

const bool &sw::AudioSource::isPlayOnStart() const
{
    return (m_playOnStart);
}

const bool sw::AudioSource::isPlaying() const
{
    int value = -1;
    alGetSourcei(m_source, AL_SOURCE_STATE, &value);
    return (value == AL_PLAYING);
}

sw::AudioSource& sw::AudioSource::setPlayOnStart(bool value)
{
    m_playOnStart = value;
    return (*this);
}