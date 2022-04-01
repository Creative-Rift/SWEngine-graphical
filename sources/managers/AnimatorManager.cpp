/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: AnimatorManager.cpp
** Description: [CHANGE]
*/

#include "SW/Engine.hpp"

#include "OpenGLModule.hpp"

#include "AnimatorManager.hpp"

void sw::AnimatorManager::onUpdate()
{
    double currentTime = sw::Engine::getModule<sw::OpenGLModule>().m_chrono.getTotalTime();

    for (auto&[_, obj]: m_components) {
        if (!obj->isActive() || !obj->entity().isActive())
            continue;
        if (!obj->isPlaying()) {
            if (obj->isLoop() && (currentTime - obj->m_lastFrame) > obj->getLoopDelay()) {
                obj->setPlaying(true);
                obj->m_displayRect.width = static_cast<float>(obj->m_rect.x);
                obj->m_displayRect.height = static_cast<float>(obj->m_rect.y);
            }
        } else if ((currentTime - obj->m_lastFrame) > obj->getFPS()) {
            if (obj->getAnimType() == sw::Animator::ANIM_LINE)
                animLine((*obj), currentTime);
            else if (obj->getAnimType() == sw::Animator::ANIM_SPRITE)
                animSprite((*obj), currentTime);
        }
    }
}

void sw::AnimatorManager::animLine(sw::Animator &animator, double &current_time)
{
    if (animator.m_displayRect.left + (float)animator.m_rect.x >= (float)animator.m_spr.texture()->getWidth() ||
        animator.m_displayRect.left / (float)animator.m_rect.x >= (float)animator.m_endFrame) {
        animator.m_displayRect.left = 0;
        animator.setPlaying(false);
    } else
        animator.m_displayRect.left += (float)animator.m_rect.x;
    animator.m_lastFrame = current_time;
    animator.m_spr.setTextureRect(animator.m_displayRect);
}

void sw::AnimatorManager::animSprite(Animator &animator, double &current_time)
{
    auto newRect = animator.m_displayRect;

    if (animator.m_displayRect.left + (float)animator.m_rect.x >= (float)animator.m_spr.texture()->getWidth()) {
        newRect.top += (float)animator.m_rect.y;
        newRect.left = 0;
    } else
        newRect.left += (float)animator.m_rect.x;
    animator.setDisplayRect(newRect);
    animator.m_lastFrame = current_time;
    animator.m_spr.setTextureRect(animator.m_displayRect);
    if (newRect.top >= (float)animator.m_spr.texture()->getHeight())
        animator.reset();
}