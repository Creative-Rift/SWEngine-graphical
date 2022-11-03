/*
** ShipWreck Engine , 2022
** MAnimator.cpp
*/

#include "glm/glm.hpp"
#include <cmath>

#include "MAnimator.hpp"
#include "Animation.hpp"
#include "Bone.hpp"

sw::MAnimator::MAnimator(sw::Animation *animation) :
m_finalBoneMatrices(),
m_currentAnimation(nullptr),
m_currentTime(0),
m_deltaTime(0)
{
    m_currentTime = 0.0;
    m_currentAnimation = animation;

    m_finalBoneMatrices.reserve(100);

    for (int i = 0; i < 100; i++)
        m_finalBoneMatrices.emplace_back(1.0f);
}

void sw::MAnimator::updateAnimation(float dt)
{
    m_deltaTime = dt;
    if (m_currentAnimation) {
        m_currentTime += m_currentAnimation->getTicksPerSecond() * dt;
        m_currentTime = fmod(m_currentTime, m_currentAnimation->getDuration());
        calculateBoneTransform(&m_currentAnimation->getRootNode(), glm::mat4(1.0f));
    }
}

void sw::MAnimator::playAnimation(sw::Animation *pAnimation)
{
    m_currentAnimation = pAnimation;
    m_currentTime = 0.0f;
}

void sw::MAnimator::calculateBoneTransform(const AssimpNodeData *node, glm::mat4 parentTransform)
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

std::vector<glm::mat4> sw::MAnimator::getFinalBoneMatrices()
{
    return (m_finalBoneMatrices);
}