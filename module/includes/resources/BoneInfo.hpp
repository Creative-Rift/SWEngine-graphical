/*
** ShipWreck Engine , 2022
** Bone.hpp
*/

#ifndef SHIPWRECK_ENGINE_BONEINFO_HPP
#define SHIPWRECK_ENGINE_BONEINFO_HPP

#include "OpenGLModule_Config.hpp"

namespace sw
{
    class SW_GRAPH_MODULE_EXPORT BoneInfo
    {
    public:
        int m_id;
        glm::mat4 m_offset;
    }; // class Bone
} // namespace sw

#endif //SHIPWRECK_ENGINE_BONEINFO_HPP
