/*
** ShipWreck Engine , 2022
** MAnimator.hpp
*/

#ifndef SHIPWRECK_ENGINE_MODELANIMATIOR_HPP
#define SHIPWRECK_ENGINE_MODELANIMATIOR_HPP

#include <string>
#include <vector>

#include "OpenGLModule_Config.hpp"
#include "Components.hpp"

namespace sw
{
    class Animation;
    class AssimpNodeData;
    class ModelAnimatorManager;

    class SW_GRAPH_MODULE_EXPORT ModelAnimator : public Component
    {
    public:
        ModelAnimator(GameObject& gameObject, std::string animationName);

        void updateAnimation(float dt);
        void playAnimation(std::string animationName);
        void calculateBoneTransform(const AssimpNodeData* node, glm::mat4 parentTransform);
        void attachModel(std::string modelName);
        [[nodiscard]]std::vector<glm::mat4> getFinalBoneMatrices();
        [[nodiscard]]Animation& getAnimation();

        void play();
        void pause();
        void stop();
        void restart();
    private:
        std::vector<glm::mat4> m_finalBoneMatrices;
        std::shared_ptr<Animation> m_currentAnimation;
        double m_currentTime;
        float m_deltaTime;
        bool m_play;
        std::string m_modelName;

        friend ModelAnimatorManager;
    };
} // namespace sw

#endif //SHIPWRECK_ENGINE_MODELANIMATIOR_HPP
