/*
** ShipWreck Engine , 2022
** Animation.cpp
*/

#include "resources/OpenResources.hpp"
#include "Model.hpp"
#include "Bone.hpp"

#include "Animation.hpp"

#include <utility>

sw::Animation::Animation(std::string &animationPath) :
m_duration(0),
m_ticksPerSecond(0),
m_bones(),
m_rootNode(),
m_boneInfoMap(),
m_scene(),
m_model(nullptr),
m_importer(),
m_path(animationPath)
{
    m_scene = m_importer.ReadFile(animationPath, aiProcess_Triangulate);
    assert(m_scene && m_scene->mRootNode);
    auto animation = m_scene->mAnimations[0];
    m_duration = animation->mDuration;
    m_ticksPerSecond = animation->mTicksPerSecond;
    readHierarchyData(m_rootNode, m_scene->mRootNode);
}

sw::Animation::~Animation() noexcept
= default;

sw::Bone *sw::Animation::findBone(const std::string &name)
{
    auto iter = std::find_if(m_bones.begin(), m_bones.end(), [&](const Bone& Bone)
    {
        return Bone.getBoneName() == name;
    });
    if (iter == m_bones.end())
        return nullptr;
    else
        return &(*iter);
}

double sw::Animation::getTicksPerSecond() const
{
    return (m_ticksPerSecond);
}

double sw::Animation::getDuration() const
{
    return (m_duration);
}

const sw::AssimpNodeData &sw::Animation::getRootNode()
{
    return (m_rootNode);
}

std::map<std::string, sw::BoneInfo> &sw::Animation::getBoneIDMap()
{
    return (m_boneInfoMap);
}

std::shared_ptr<sw::Model> sw::Animation::getModel()
{
    return (m_model);
}

void sw::Animation::readMissingBones(const aiAnimation *animation, sw::Model &model)
{
    unsigned int size = animation->mNumChannels;

    auto& boneInfoMap = model.getBones();
    int& boneCount = model.getBonesNumber();

    for (int i = 0; i < size; i++) {
        auto channel = animation->mChannels[i];
        std::string boneName = channel->mNodeName.data;

        if (boneInfoMap.find(boneName) == boneInfoMap.end()) {
            boneInfoMap[boneName].m_id = boneCount;
            boneCount++;
        }
        m_bones.emplace_back(channel->mNodeName.data, boneInfoMap[channel->mNodeName.data].m_id, channel);
    }
    m_boneInfoMap = boneInfoMap;
}

glm::mat4 ConvertMatrixToGLMFormat(const aiMatrix4x4& from)
{
    glm::mat4 to;

    to[0][0] = from.a1; to[1][0] = from.a2; to[2][0] = from.a3; to[3][0] = from.a4;
    to[0][1] = from.b1; to[1][1] = from.b2; to[2][1] = from.b3; to[3][1] = from.b4;
    to[0][2] = from.c1; to[1][2] = from.c2; to[2][2] = from.c3; to[3][2] = from.c4;
    to[0][3] = from.d1; to[1][3] = from.d2; to[2][3] = from.d3; to[3][3] = from.d4;
    return (to);
}

void sw::Animation::readHierarchyData(sw::AssimpNodeData &dest, const aiNode *src)
{
    dest.name = src->mName.data;
    dest.transformation = ConvertMatrixToGLMFormat(src->mTransformation);
    dest.childrenCount = static_cast<int>(src->mNumChildren);

    for (int i = 0; i < src->mNumChildren; i++){
        AssimpNodeData newData;
        readHierarchyData(newData, src->mChildren[i]);
        dest.children.push_back(newData);
    }
}

sw::Animation& sw::Animation::attachModel(std::string modelName)
{
    m_model = sw::OpenResources::m_nmodel[std::move(modelName)];
    readMissingBones(m_scene->mAnimations[0], *m_model);
    return (*this);
}

sw::Animation &sw::Animation::defineAnimation(int index)
{
    readMissingBones(m_scene->mAnimations[index], *m_model);
    return (*this);
}