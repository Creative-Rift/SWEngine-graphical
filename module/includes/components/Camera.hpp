/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Camera.hpp
** Description: [CHANGE]
*/

#ifndef SWENGINE_OPENGLMODULE_CAMERA_HPP
#define SWENGINE_OPENGLMODULE_CAMERA_HPP

#include "base/Component.hpp"
#include "dependencies/glm/glm.hpp"
#include "utils/Reference.hpp"

#include "OpenGLModule_Config.hpp"

namespace sw
{

    class CameraManager;
    class Scene;

    class SW_GRAPH_MODULE_EXPORT Camera : public sw::Component
    {
        public:
            enum Projection {
                ORTHOGRAPHIC,
                PERSPECTIVE,
            };

            explicit Camera(sw::GameObject& gameObject);
            ~Camera() override = default;
            Camera& setProjection(Projection projection);
            Camera& setFov(float fov);
            Camera& setSize(float size);
            Camera& setClipping(float near, float far);
            Camera& setClippingNear(float near);
            Camera& setClippingFar(float far);
            Camera& setPitch(float newPitch);
            Camera& setYaw(float newYaw);

            [[nodiscard]] const glm::mat4& getProjection();
            [[nodiscard]] glm::mat4 getView();
            [[nodiscard]] float getPitch() const;
            [[nodiscard]] float getYaw() const;
            [[nodiscard]] glm::vec3 getFront() const;
            [[nodiscard]] glm::vec3 getRight() const;

            [[nodiscard]] YAML::Node save() const;

        private:
            Projection m_type;
            float m_fov;
            float m_size;
            float m_clippingNear;
            float m_clippingFar;
            float m_pitch;
            float m_yaw;

            glm::mat4 m_view;
            glm::vec3 m_front;
            glm::vec3 m_up;
            glm::vec3 m_right;

            void updateVectors();

            friend CameraManager;
            friend Scene;
    }; // class Camera
} // namespace sw

#endif //SWENGINE_OPENGLMODULE_CAMERA_HPP
