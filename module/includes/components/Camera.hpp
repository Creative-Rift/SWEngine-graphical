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

#include "OpenGLModule_Config.hpp"

namespace sw
{

    class CameraManager;

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

            [[nodiscard]] const glm::mat4& getProjection();
            [[nodiscard]] const glm::mat4 getView() const;

            YAML::Node save() const;

        private:
            Projection m_type;
            float m_fov;
            float m_size;
            float m_clippingNear;
            float m_clippingFar;

            glm::mat4 m_view;

            friend CameraManager;
    }; // class Camera
} // namespace sw

#endif //SWENGINE_OPENGLMODULE_CAMERA_HPP
