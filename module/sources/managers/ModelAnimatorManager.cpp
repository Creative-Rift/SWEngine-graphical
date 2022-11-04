/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: ModelAnimatorManager.cpp
*/

#include "OpenGLModule.hpp"

#include "managers/ModelAnimatorManager.hpp"

void sw::ModelAnimatorManager::onUpdate()
{
    for (auto& [_, obj] : m_components) {
        if (!obj->isActive() || !obj->gameObject().isActive())
            continue;
        obj->updateAnimation(sw::OpenGLModule::chrono().getElapsedTime());
        auto transforms = obj->getFinalBoneMatrices();
        obj->m_currentAnimation->getModel()->shader->useShader();
        for (int i = 0; i < transforms.size(); ++i)
            obj->m_currentAnimation->getModel()->shader->setUniMat4("finalBonesMatrices[" + std::to_string(i) + "]", transforms[i]);
    }
}
