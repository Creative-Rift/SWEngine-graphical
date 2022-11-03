/*
** ShipWreck Engine , 2022
** MAnimator.hpp
*/

#ifndef SHIPWRECK_ENGINE_MANIMATOR_HPP
#define SHIPWRECK_ENGINE_MANIMATOR_HPP

#include <string>
#include <vector>

#include "OpenGLModule_Config.hpp"

namespace sw
{
    class Animation;
    class AssimpNodeData;

    class SW_GRAPH_MODULE_EXPORT MAnimator
    {
    public:
        MAnimator(Animation* Animation);

        void updateAnimation(float dt);

        void playAnimation(Animation* pAnimation);

        void calculateBoneTransform(const AssimpNodeData* node, glm::mat4 parentTransform);

        std::vector<glm::mat4> getFinalBoneMatrices();

    private:
        std::vector<glm::mat4> m_finalBoneMatrices;
        Animation* m_currentAnimation;
        float m_currentTime;
        float m_deltaTime;
    };
} // namespace sw

#endif //SHIPWRECK_ENGINE_MANIMATOR_HPP
