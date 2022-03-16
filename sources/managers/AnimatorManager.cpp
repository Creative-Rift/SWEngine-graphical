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
        if (!obj->isPlaying()) {
            if (obj->isLoop() && (currentTime - obj->getLastFrame()) > obj->getLoopDelay()) {
                obj->setPlaying(true);
                obj->getDisplayRect().width = static_cast<float>(obj->getRect().x);
                obj->getDisplayRect().height = static_cast<float>(obj->getRect().y);
            }
        } else if ((currentTime - obj->getLastFrame()) > obj->getFPS()) {
            if ((*obj).getAnimType() == sw::Animator::ANIM_LINE) {
                animLine((*obj), currentTime);
            } else if ((*obj).getAnimType() == sw::Animator::ANIM_SPRITE)
                animSprite((*obj), currentTime);
        }
    }
}

void sw::AnimatorManager::animLine(sw::Animator &animator, double &current_time)
{
    if (animator.getDisplayRect().left + animator.getRect().x >= animator.getSprite().texture()->getWidth() ||
        animator.getDisplayRect().left / animator.getRect().x >= (float)animator.getEndFrame()) {
        animator.getDisplayRect().left = 0;
        animator.setPlaying(false);
    } else
        animator.getDisplayRect().left += animator.getRect().x;
    animator.getLastFrame() = current_time;
    animator.getSprite().setTextureRect(animator.getDisplayRect());
}

void sw::AnimatorManager::animSprite(Animator &animator, double &current_time)
{
    auto newRect = animator.getDisplayRect();

    if (animator.getDisplayRect().left + animator.getRect().x >= animator.getSprite().texture()->getWidth()) {
        newRect.top += animator.getRect().y;
        newRect.left = 0;
    } else
        newRect.left += animator.getRect().x;
    animator.setDisplayRect(newRect);
    animator.getLastFrame() = current_time;
    animator.getSprite().setTextureRect(animator.getDisplayRect());
    if (newRect.top >= animator.getSprite().texture()->getHeight())
        animator.reset();
}