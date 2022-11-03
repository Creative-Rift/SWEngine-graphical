/*
** ShipWreck Engine , 2022
** Animation.hpp
*/

#ifndef SHIPWRECK_ENGINE_ANIMATION_HPP
#define SHIPWRECK_ENGINE_ANIMATION_HPP

#include <string>
#include <vector>
#include <map>

#include "dependencies/glm/glm.hpp"
#include "assimp/scene.h"

#include "OpenGLModule_Config.hpp"

#include "BoneInfo.hpp"
#include "Bone.hpp"

namespace sw
{
    class Model;
    struct SW_GRAPH_MODULE_EXPORT AssimpNodeData;

    struct AssimpNodeData
    {
        glm::mat4 transformation;
        std::string name;
        int childrenCount;
        std::vector<AssimpNodeData> children;
    };

    class SW_GRAPH_MODULE_EXPORT Animation
    {
    public:
        Animation() = delete;

        Animation(const std::string& animationPath, std::string modelName);

        ~Animation();

        Bone* findBone(const std::string& name);
        float getTicksPerSecond();
        float getDuration();
        const AssimpNodeData& getRootNode();
        std::map<std::string, BoneInfo>& getBoneIDMap();

    private:
        void readMissingBones(const aiAnimation* animation, Model& model);
        void readHeirarchyData(AssimpNodeData& dest, const aiNode* src);
        float m_duration;
        int m_ticksPerSecond;
        std::vector<Bone> m_bones;
        AssimpNodeData m_rootNode;
        std::map<std::string, BoneInfo> m_boneInfoMap;
    };
} // namespace sw

#endif //SHIPWRECK_ENGINE_ANIMATION_HPP
