/*
** ShipWreck Engine , 2022
** Bone.hpp
*/

#ifndef SHIPWRECK_ENGINE_BONE_HPP
#define SHIPWRECK_ENGINE_BONE_HPP

#include <vector>
#include <string>

#include "OpenGLModule_Config.hpp"
#include "dependencies/glm/glm.hpp"
#include "dependencies/glm/gtc/quaternion.hpp"
#include "assimp/anim.h"

namespace sw
{
    struct SW_GRAPH_MODULE_EXPORT KeyTransform
    {
        glm::vec3 m_position;
        glm::quat m_rotation;
        glm::vec3 m_scale;
        float m_timeStamp;
    };

    struct SW_GRAPH_MODULE_EXPORT KeyPos
    {
        glm::vec3 m_position;
        float m_timeStamp;
    };

    struct SW_GRAPH_MODULE_EXPORT KeyRot
    {
        glm::quat m_rotation;
        float m_timeStamp;
    };

    struct SW_GRAPH_MODULE_EXPORT KeyScale
    {
        glm::vec3 m_scale;
        float m_timeStamp;
    };


    class SW_GRAPH_MODULE_EXPORT Bone
    {
    public:
        Bone(const std::string& name, int ID, const aiNodeAnim* channel);
        void update(float animationTime);
        glm::mat4 getLocalTransform();
        std::string getBoneName() const;
        int getBoneID();
        int getPositionIndex(float animationTime);
        int getRotationIndex(float animationTime);
        int getScaleIndex(float animationTime);

    private:
        std::vector<KeyPos> m_pos;
        std::vector<KeyRot> m_rot;
        std::vector<KeyScale> m_scale;
        int m_numPositions;
        int m_numRotations;
        int m_numScalings;

        glm::mat4 m_localTransform;
        std::string m_name;
        int m_id;

        float getScaleFactor(float lastTimeStamp, float nextTimeStamp, float animationTime);
        glm::mat4 interpolatePosition(float animationTime);
        glm::mat4 interpolateRotation(float animationTime);
        glm::mat4 interpolateScaling(float animationTime);

    }; // class Bone
} // namespace sw

#endif //SHIPWRECK_ENGINE_BONE_HPP
