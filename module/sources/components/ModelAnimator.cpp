/*
** ShipWreck Engine , 2022
** ModelAnimator.cpp
*/

#include "glm/glm.hpp"
#include <utility>

#include "ModelAnimator.hpp"
#include "Animation.hpp"
#include "Bone.hpp"

sw::ModelAnimator::ModelAnimator(GameObject& gameObject, std::string animationName) :
sw::Component(gameObject),
m_finalBoneMatrices(),
m_currentAnimation(nullptr),
m_currentTime(0),
m_deltaTime(0),
m_play(true)
{
    m_currentTime = 0.0;
    m_currentAnimation = sw::OpenResources::m_nanimation[std::move(animationName)];
    m_finalBoneMatrices.reserve(100);
    for (int i = 0; i < 100; i++)
        m_finalBoneMatrices.emplace_back(1.0f);
    updateAnimation(0.1);
}

void sw::ModelAnimator::updateAnimation(float dt)
{
    m_deltaTime = dt;
    if (m_currentAnimation) {
        m_currentTime += m_currentAnimation->getTicksPerSecond() * dt;
        m_currentTime = fmod(m_currentTime, m_currentAnimation->getDuration());
        calculateBoneTransform(&m_currentAnimation->getRootNode(), glm::mat4(1.0f));
    }
}

void sw::ModelAnimator::playAnimation(std::string animationName)
{
    if (m_animName == animationName)
        return;
    m_animName = animationName;
    m_currentAnimation = sw::OpenResources::m_nanimation[std::move(animationName)];
    m_currentAnimation->attachModel(m_modelName);
    m_currentTime = 0.0f;
}

void sw::ModelAnimator::calculateBoneTransform(const AssimpNodeData *node, glm::mat4 parentTransform)
{
    std::string nodeName = node->name;
    glm::mat4 nodeTransform = node->transformation;

    Bone* Bone = m_currentAnimation->findBone(nodeName);

    if (Bone) {
        Bone->update(m_currentTime);
        nodeTransform = Bone->getLocalTransform();
    }

    glm::mat4 globalTransformation = parentTransform * nodeTransform;

    auto boneInfoMap = m_currentAnimation->getBoneIDMap();
    if (boneInfoMap.find(nodeName) != boneInfoMap.end())
    {
        int index = boneInfoMap[nodeName].m_id;
        glm::mat4 offset = boneInfoMap[nodeName].m_offset;
        m_finalBoneMatrices[index] = globalTransformation * offset;
    }

    for (int i = 0; i < node->childrenCount; i++)
        calculateBoneTransform(&node->children[i], globalTransformation);
}

void sw::ModelAnimator::attachModel(std::string modelName)
{
    m_modelName = modelName;
    m_currentAnimation->attachModel(m_modelName);
}

std::vector<glm::mat4> sw::ModelAnimator::getFinalBoneMatrices()
{
    return (m_finalBoneMatrices);
}

sw::Animation &sw::ModelAnimator::getAnimation()
{
    return (*m_currentAnimation);
}

void sw::ModelAnimator::play()
{
    m_play = true;
}

void sw::ModelAnimator::pause()
{
    m_play = false;
}

void sw::ModelAnimator::stop()
{
    m_play = false;
    m_currentTime = 0;
    m_deltaTime = 0;
}

void sw::ModelAnimator::restart()
{
    stop();
    play();
}