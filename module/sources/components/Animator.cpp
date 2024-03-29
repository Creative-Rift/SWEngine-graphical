/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Animator.cpp
** Description: [CHANGE]
*/

#include "components/Animator.hpp"

sw::Animator::Animator(sw::GameObject& gameObject) :
sw::Component(gameObject),
m_rect(),
m_displayRect(),
m_lastFrame(-1),
m_endFrame(-1),
m_loopDelay(0.0f),
m_isPlaying(false),
m_loop(false),
m_framePerSecond(0.2),
m_spr(gameObject.getComponent<sw::Sprite>("SpriteManager")),
m_type(ANIM_SPRITE),
m_playOnStart(true)
{
    m_displayRect = {0, 0, static_cast<float>(m_spr.texture()->getWidth()), static_cast<float>(m_spr.texture()->getHeight())};
    gameObject.scene().eventManager["Start"].subscribe(m_gameObject.name(), this, &Animator::playOnStart);
}

void sw::Animator::playOnStart()
{
    if (m_playOnStart)
        play();
}

bool sw::Animator::isPlaying() const
{
    return (m_isPlaying);
}

void sw::Animator::play()
{
    m_isPlaying = true;
}

void sw::Animator::pause()
{
    m_isPlaying = false;
}

void sw::Animator::reset()
{
    m_isPlaying = false;
    m_displayRect = {0, 0, static_cast<float>(m_rect.y), static_cast<float>(m_rect.x)};
}

sw::Animator& sw::Animator::setLoop(bool loop, float delay)
{
    m_loop = loop;
    m_loopDelay = delay;
    return (*this);
}

sw::Animator& sw::Animator::setLine(int line, int end)
{
    if (line * m_rect.y >= m_spr.texture()->getHeight()) {
        std::cout << "The line line is out of range!\n";
        return (*this);
    }
    m_endFrame = (end == -1) ? (int)(m_spr.texture()->getWidth() / m_rect.x) + 1 : end;
    m_displayRect.top = (float)line * (float)m_rect.y;
    return (*this);
}

sw::Animator& sw::Animator::setRect(sw::Vector2u rect)
{
    m_rect = rect;
    m_displayRect.height = (float)m_rect.y;
    m_displayRect.width = (float)m_rect.x;
    m_endFrame = (int)(m_spr.texture()->getWidth() / m_rect.x) + 1;
    m_spr.setTextureRect(m_displayRect);
    return (*this);
}

sw::Animator& sw::Animator::setFPS(float fps)
{
    m_framePerSecond = 1.0f / fps;
    return (*this);
}

sw::Animator& sw::Animator::setPlayOnStart(bool value)
{
    m_playOnStart = value;
    return (*this);
}

const bool &sw::Animator::isLoop() const
{
    return (m_loop);
}

const sw::Vector2u &sw::Animator::getRect() const
{
    return (m_rect);
}

const float &sw::Animator::getLoopDelay() const
{
    return (m_loopDelay);
}

const float &sw::Animator::getFPS() const
{
    return (m_framePerSecond);
}

sw::Animator &sw::Animator::setAnimType(sw::Animator::AnimType type)
{
    m_type = type;
    return (*this);
}

sw::Animator::AnimType &sw::Animator::getAnimType()
{
    return (m_type);
}

const bool &sw::Animator::getPlayOnStart()
{
    return (m_playOnStart);
}

YAML::Node sw::Animator::save() const
{
    YAML::Node node;

    node["entity_name"] = name();
    node["rect"].push_back(m_rect.x);
    node["rect"].push_back(m_rect.y);
    node["displayRect"].push_back(m_displayRect.top);
    node["displayRect"].push_back(m_displayRect.left);
    node["displayRect"].push_back(m_displayRect.width);
    node["displayRect"].push_back(m_displayRect.height);
    node["endFrame"] = m_endFrame;
    node["loopDelay"] = m_loopDelay;
    node["loop"] = m_loop;
    node["playOnStart"] = m_playOnStart;
    node["fps"] = m_framePerSecond;
    node["type"] = m_type == ANIM_LINE ? 1 : 0;

    return (node);
}