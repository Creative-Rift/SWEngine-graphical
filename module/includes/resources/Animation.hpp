/*
** ShipWreck Engine , 2022
** Animation.hpp
*/

#ifndef SHIPWRECK_ENGINE_ANIMATION_HPP
#define SHIPWRECK_ENGINE_ANIMATION_HPP

#include <string>
#include <vector>
#include <map>

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "dependencies/glm/glm.hpp"

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
        explicit Animation(std::string& animationPath);
        ~Animation();

        [[nodiscard]] Bone* findBone(const std::string& name);
        [[nodiscard]] double getTicksPerSecond() const;
        [[nodiscard]] double getDuration() const;
        [[nodiscard]] const AssimpNodeData& getRootNode();
        [[nodiscard]] std::map<std::string, BoneInfo>& getBoneIDMap();
        [[nodiscard]] std::shared_ptr<Model> getModel();
        sw::Animation& attachModel(std::string modelName);
        sw::Animation& defineAnimation(int index);

    private:
        void readMissingBones(const aiAnimation* animation, Model& model);
        void readHierarchyData(AssimpNodeData& dest, const aiNode* src);
        double m_duration;
        double m_ticksPerSecond;
        std::vector<Bone> m_bones;
        AssimpNodeData m_rootNode;
        std::map<std::string, BoneInfo> m_boneInfoMap;
        const aiScene* m_scene;
        std::shared_ptr<Model> m_model;
        Assimp::Importer m_importer;
        std::string m_path;

    };
} // namespace sw

#endif //SHIPWRECK_ENGINE_ANIMATION_HPP
