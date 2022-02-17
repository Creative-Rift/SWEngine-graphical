/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Animator.cpp
** Description: [CHANGE]
*/

#include "components/Animator.hpp"

sw::Animator::Animator(sw::Entity& entityRef) :
sw::Component(entityRef),
m_rect(),
m_displayRect(),
m_lastFrame(-1.0f),
m_endFrame(-1.0f),
m_loopDelay(0.0f),
m_isPlaying(false),
m_loop(true),
m_framePerSecond(0.2),
m_spr(entityRef.getComponent<sw::Sprite>("SpriteManager")),
m_animType(ANIM_SPRITE)
{
    //m_displayRect = {0, 0, (float)m_spr.texture().getSize().x, (float)m_spr.texture().getSize().y};
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
    m_displayRect = {0, 0, (float)m_rect.x, (float)m_rect.y};
}

sw::Animator& sw::Animator::setLoop(bool loop, float delay)
{
    m_loop = loop;
    m_loopDelay = delay;
    return (*this);
}

sw::Animator& sw::Animator::setLine(int line, int end)
{
    //if (line * m_rect.y >= m_spr.texture().getSize().y) {
    //    std::cout << "The line line is out of range!\n";
    //    return (*this);
    //}
    //m_endFrame = (end == -1) ? (int)(m_spr.texture().getSize().x / m_rect.x) + 1 : end;
    m_displayRect.top = line * m_rect.y;
    return (*this);
}

sw::Animator& sw::Animator::setRect(sw::Vector2u rect)
{
    m_rect = rect;
    m_displayRect.height = m_rect.y;
    m_displayRect.width = m_rect.x;
    //m_endFrame = (int)(m_spr.texture().getSize().x / m_rect.x) + 1;
    m_displayRect.left -= m_rect.x;
    m_spr.setTextureRect(m_displayRect);
    return (*this);
}

sw::Animator& sw::Animator::setFPS(float fps)
{
    m_framePerSecond = 1.0f / fps;
    return (*this);
}