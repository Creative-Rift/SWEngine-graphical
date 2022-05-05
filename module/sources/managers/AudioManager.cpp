/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: AudioSourceManager.hpp
** Description: [CHANGE]
*/

#include "AudioSourceManager.hpp"

void sw::AudioSourceManager::onUpdate()
{
    for (auto& [_, audioSource] : m_components) {
        alGetSourcef(audioSource->m_source, AL_SEC_OFFSET, &audioSource->m_currentSample);
        if (audioSource->m_endLoopPoint != -1 && audioSource->m_endLoopPoint <= audioSource->m_currentSample) {
            audioSource->stop();
            alSourcef(audioSource->m_source, AL_SEC_OFFSET, audioSource->m_startLoopPoint);
            audioSource->play();
        }
        if (audioSource->m_endPoint != -1 && audioSource->m_endPoint <= audioSource->m_currentSample)
            audioSource->stop();
    }
}