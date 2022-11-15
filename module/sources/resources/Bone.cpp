/*
** ShipWreck Engine , 2022
** Bone.cpp
*/

#include "Bone.hpp"
#include "glm/gtx/quaternion.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Error.hpp"

sw::Bone::Bone(const std::string &name, int id, const aiNodeAnim *channel) :
m_name(name),
m_id(id),
m_localTransform(1.0f)
{
    m_numPositions = channel->mNumPositionKeys;

    for (int positionIndex = 0; positionIndex < m_numPositions; ++positionIndex)
    {
        aiVector3D aiPosition = channel->mPositionKeys[positionIndex].mValue;
        float timeStamp = channel->mPositionKeys[positionIndex].mTime;
        KeyPos data;
        data.m_position.x = aiPosition.x;
        data.m_position.y = aiPosition.y;
        data.m_position.z = aiPosition.z;
        data.m_timeStamp = timeStamp;
        m_pos.push_back(data);
    }

    m_numRotations = channel->mNumRotationKeys;
    for (int rotationIndex = 0; rotationIndex < m_numRotations; ++rotationIndex)
    {
        aiQuaternion aiOrientation = channel->mRotationKeys[rotationIndex].mValue;
        float timeStamp = channel->mRotationKeys[rotationIndex].mTime;
        KeyRot data;
        data.m_rotation.x = aiOrientation.x;
        data.m_rotation.y = aiOrientation.y;
        data.m_rotation.z = aiOrientation.z;
        data.m_rotation.w = aiOrientation.w;
        data.m_timeStamp = timeStamp;
        m_rot.push_back(data);
    }

    m_numScalings = channel->mNumScalingKeys;
    for (int keyIndex = 0; keyIndex < m_numScalings; ++keyIndex)
    {
        aiVector3D scale = channel->mScalingKeys[keyIndex].mValue;
        float timeStamp = channel->mScalingKeys[keyIndex].mTime;
        KeyScale data;
        data.m_scale.x = scale.x;
        data.m_scale.y = scale.y;
        data.m_scale.z = scale.z;
        data.m_timeStamp = timeStamp;
        m_scale.push_back(data);
    }
}

void sw::Bone::update(float animationTime)
{
    glm::mat4 translation = interpolatePosition(animationTime);
    glm::mat4 rotation = interpolateRotation(animationTime);
    glm::mat4 scale = interpolateScaling(animationTime);
    m_localTransform = translation * rotation * scale;
}

glm::mat4 sw::Bone::getLocalTransform()
{
    return m_localTransform;
}

std::string sw::Bone::getBoneName() const
{
    return (m_name);
}

int sw::Bone::getBoneID()
{
    return (m_id);
}

int sw::Bone::getPositionIndex(float animationTime)
{
    for (int index = 0; index < m_numPositions - 1; ++index)
    {
        if (animationTime < m_pos[index + 1].m_timeStamp)
            return index;
    }
    return 0;
}

int sw::Bone::getRotationIndex(float animationTime)
{
    for (int index = 0; index < m_numRotations - 1; ++index)
    {
        if (animationTime < m_rot[index + 1].m_timeStamp)
            return index;
    }
    assert(0);
    throw sw::Error("", "");
}

int sw::Bone::getScaleIndex(float animationTime)
{
    for (int index = 0; index < m_numScalings - 1; ++index)
    {
        if (animationTime < m_scale[index + 1].m_timeStamp)
            return index;
    }
    assert(0);
    throw sw::Error("", "");
}

float sw::Bone::getScaleFactor(float lastTimeStamp, float nextTimeStamp, float animationTime)
{
    float scaleFactor = 0.0f;
    float midWayLength = animationTime - lastTimeStamp;
    float framesDiff = nextTimeStamp - lastTimeStamp;
    scaleFactor = midWayLength / framesDiff;
    return scaleFactor;
}

glm::mat4 sw::Bone::interpolatePosition(float animationTime)
{
    if (1 == m_numPositions)
        return glm::translate(glm::mat4(1.0f), m_pos[0].m_position);

    int p0Index = getPositionIndex(animationTime);
    int p1Index = p0Index + 1;
    float scaleFactor = getScaleFactor(m_pos[p0Index].m_timeStamp, m_pos[p1Index].m_timeStamp, animationTime);
    glm::vec3 finalPosition = glm::mix(m_pos[p0Index].m_position, m_pos[p1Index].m_position, scaleFactor);
    return glm::translate(glm::mat4(1.0f), finalPosition);
}

glm::mat4 sw::Bone::interpolateRotation(float animationTime)
{
    if (1 == m_numRotations)
    {
        auto rotation = glm::normalize(m_rot[0].m_rotation);
        return glm::toMat4(rotation);
    }

    int p0Index = getRotationIndex(animationTime);
    int p1Index = p0Index + 1;
    float scaleFactor = getScaleFactor(m_rot[p0Index].m_timeStamp, m_rot[p1Index].m_timeStamp, animationTime);
    glm::quat finalRotation = glm::slerp(m_rot[p0Index].m_rotation, m_rot[p1Index].m_rotation, scaleFactor);
    finalRotation = glm::normalize(finalRotation);
    return glm::toMat4(finalRotation);
}

glm::mat4 sw::Bone::interpolateScaling(float animationTime)
{
    if (1 == m_numScalings)
        return glm::scale(glm::mat4(1.0f), m_scale[0].m_scale);

    int p0Index = getScaleIndex(animationTime);
    int p1Index = p0Index + 1;
    float scaleFactor = getScaleFactor(m_scale[p0Index].m_timeStamp, m_scale[p1Index].m_timeStamp, animationTime);
    glm::vec3 finalScale = glm::mix(m_scale[p0Index].m_scale, m_scale[p1Index].m_scale, scaleFactor);
    return glm::scale(glm::mat4(1.0f), finalScale);
}